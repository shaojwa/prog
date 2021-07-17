

#include "sock.h"
#include "log.h"

#include <stdio.h>
#include <iostream>
using namespace std;



Sock::Sock():
m_skTcpListen(INVALID_SOCKET),
m_skUdpListen(INVALID_SOCKET),
m_skTcpConn(INVALID_SOCKET),
m_skUdpConn(INVALID_SOCKET),
m_skAccept(INVALID_SOCKET) {
}


Sock::~Sock() {
}


bool Sock::startup() {
    WSADATA wsaData = {0};
    int result = WSAStartup(MAKEWORD(2,2), &wsaData);
    if (result != 0) {
        logline(LOG::LEVEL_FATAL, "WSAStartup failed.(error = %d)", GetLastError());
        return false;
    }
    return true;
}


bool Sock::cleanup() {
    if (0 != WSACleanup()) {
        logline(LOG::LEVEL_FATAL, "WSACleanup failed.(error = %d)", GetLastError());
        return false;
    }
    return true;
}



bool Sock::init() {
    InitializeCriticalSection(&m_csSocks);
    return true;
}


bool Sock::release() {
    return true;
}


void Sock::pushSock(SOCKET sk) {
    EnterCriticalSection(&m_csSocks);
    m_lstSocks.push_back(sk);
    LeaveCriticalSection(&m_csSocks);
}


SOCKET Sock::popSock() {
    SOCKET sock = INVALID_SOCKET;
    EnterCriticalSection(&m_csSocks);
    sock = m_lstSocks.front();
    m_lstSocks.pop_front();
    LeaveCriticalSection(&m_csSocks);
    return sock;
}



bool Sock::listenTcp(int listenPort) {
    m_listenPort = listenPort;
    m_skTcpListen = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
    if (m_skTcpListen == INVALID_SOCKET) {
        logline(LOG::LEVEL_FATAL, "socket() fail. (error = %d)", GetLastError());
        return false;
    }
    m_saLocal.sin_family = AF_INET;
    m_saLocal.sin_addr.s_addr = inet_addr("0.0.0.0");
    m_saLocal.sin_port = htons(m_listenPort);
    int ret = 0;

    ret = bind(m_skTcpListen, (sockaddr *)&m_saLocal, sizeof(m_saLocal));
    if (SOCKET_ERROR == ret) {
        logline(LOG::LEVEL_FATAL, "bind() fail.");
        return false;
    }

    ret = listen(m_skTcpListen, SOMAXCONN);
    if (SOCKET_ERROR == ret) {
        logline(LOG::LEVEL_FATAL, "listen() fail.");
        return false;
    }

    while(true) {
        m_skAccept = accept(m_skTcpListen, NULL, NULL);
        if (INVALID_SOCKET == m_skAccept) {
            logline(LOG::LEVEL_FATAL, "accept() fail.");
            return false;
        } else {
            logline(LOG::LEVEL_INFO, "new connect socket = %d.", m_skAccept);
            pushSock(m_skAccept);
        }
    }
    return true;
}


bool Sock::connectTo(const char * hostIp, uint16_t port) {
    struct sockaddr_in saRemote;
    DWORD dwRet = 0;
    saRemote.sin_family = AF_INET;
    saRemote.sin_port = htons(port);
    saRemote.sin_addr.s_addr = inet_addr(hostIp);

    m_skTcpConn = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
    int ret = connect(m_skTcpConn, (sockaddr *)&saRemote, sizeof(saRemote));
    if (ret == SOCKET_ERROR) {
        logline(LOG::LEVEL_ERROR, "connect failed.(error = %d)", GetLastError());
        return false;
    }
    return true;
}



bool Sock::listenUdp(int listenPort)
{
    int result = 0;
    m_skUdpListen = socket(AF_INET, SOCK_DGRAM, IPPROTO_UDP);
    if (m_skUdpListen == INVALID_SOCKET) {
        logline(LOG::LEVEL_FATAL,"socket failed. (error = %d)", GetLastError());
        return false;
    }

    m_listenPort =  listenPort;
    m_saLocal.sin_family = AF_INET;
    m_saLocal.sin_addr.s_addr = htonl(INADDR_ANY);
    logline(LOG::LEVEL_INFO, "listen port = %d", listenPort);
    m_saLocal.sin_port = htons(m_listenPort);

    result = bind(m_skUdpListen, (SOCKADDR *)&m_saLocal, sizeof(m_saLocal));
    if (result != 0) {
        logline(LOG::LEVEL_FATAL, "bind failed, error(%d)", GetLastError());
        return false;
    }
    logline(LOG::LEVEL_INFO, "bind success");

    while(true) {
        int32_t recvBytes = recvfrom(m_skUdpListen, m_recvBuf, sizeof(m_recvBuf), 0, NULL, NULL);
        logline(LOG::LEVEL_INFO, "recvfrom return %d", recvBytes);
        if (recvBytes > 0) {
            logline(LOG::LEVEL_FATAL, "recv %d bytes.", recvBytes);
        } else if (recvBytes == SOCKET_ERROR) {
            logline(LOG::LEVEL_FATAL, "recvfrom failed. (error = %d): ", GetLastError());
            break;
        } else {
            logline(LOG::LEVEL_FATAL, "recvfrom failed. error(%d)", GetLastError());
            break;
        }
    }
    return true;
}


bool Sock::sendUdp(const uint8_t *buf, size_t len) {

    m_skUdpConn = socket(AF_INET, SOCK_DGRAM, IPPROTO_UDP);
    if (m_skUdpConn == INVALID_SOCKET) {
        logline(LOG::LEVEL_FATAL, "socket failed in %s (error=%d).",
             __FUNCTION__, GetLastError());
        return false;
    }

    m_saRemote.sin_family = AF_INET;
    m_saRemote.sin_port = htons(m_remotePort);
    m_saRemote.sin_addr.s_addr = inet_addr(m_szRemoteIp);

    int32_t sentBytes = sendto(m_skUdpConn, (char *)buf, len, 0,
        (SOCKADDR *)&m_saRemote, sizeof(m_saRemote));

    if (sentBytes > 0) {
        logline(LOG::LEVEL_INFO, "sent %d bytes to the remote", sentBytes);
        return true;
    } else if (sentBytes == SOCKET_ERROR) {
        logline(LOG::LEVEL_FATAL, "sendto failed(error = %d).", GetLastError());
        return false;
    } else {
        logline(LOG::LEVEL_FATAL, "sendto failed. (error = %d)", GetLastError());
        return false;
    }
}


bool Sock::sendTcp(const uint8_t *buf, size_t len) {
    m_skTcpConn = socket(AF_INET, SOCK_DGRAM, IPPROTO_TCP);
    if (m_skTcpConn == INVALID_SOCKET) {
        logline(LOG::LEVEL_FATAL, "socket failed in %s (error=%d).",
            __FUNCTION__, GetLastError());
        return false;
    }

    m_saRemote.sin_family = AF_INET;
    m_saRemote.sin_port = htons(m_remotePort);
    m_saRemote.sin_addr.s_addr = inet_addr(m_szRemoteIp);

    int ret = connect(m_skTcpConn, (SOCKADDR *)&m_saRemote, sizeof(m_saRemote));
    if (ret == SOCKET_ERROR) {
        logline(LOG::LEVEL_INFO, "connect failed (error = %d", GetLastError());
        return false;
    }

    int32_t sentBytes = send(m_skTcpConn, (char *)buf, len, 0);
    if (sentBytes > 0) {
        logline(LOG::LEVEL_INFO, "sent %d bytes to the remote", sentBytes);
        return true;
    } else if (sentBytes == SOCKET_ERROR) {
        logline(LOG::LEVEL_FATAL, "sendto failed(error = %d).", GetLastError());
        return false;
    } else {
        logline(LOG::LEVEL_FATAL, "sendto failed. (error = %d)", GetLastError());
        return false;
    }
}

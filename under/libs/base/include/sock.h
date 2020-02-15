

#ifndef SOCK_H
#define SOCK_H

#include "type.h"
#include <winsock2.h>
#include <windows.h>

#include <iostream>
#include <list>
using namespace std;

#define MAX_LEN_BUF (1024*1024)
#define DllExport __declspec( dllexport )

class DllExport Sock {
public:
    static bool startup(void);
    static bool cleanup(void);

    Sock(void);
    ~Sock(void);

    bool init();
    bool release();

    bool listenTcp(const int listenPort);
    bool listenUdp(const int listenPort);
    bool connectTo(const char * hostIp, uint16_t port);
    bool sendUdp(const uint8_t *buf, size_t len);
    bool sendTcp(const uint8_t *buf, size_t len);

private:
    void pushSock(SOCKET sk);
    SOCKET popSock();

    sockaddr_in m_saLocal;
    sockaddr_in m_saRemote;

    SOCKET m_skTcpListen;
    SOCKET m_skUdpListen;
    SOCKET m_skUdpConn;
    SOCKET m_skTcpConn;
    SOCKET m_skAccept;

    list<SOCKET> m_lstSocks;

    CRITICAL_SECTION m_csSocks;

    uint16_t m_listenPort;
    uint16_t m_remotePort;

    char m_szRemoteIp[32];
    char m_sendBuf[MAX_LEN_BUF];
    char m_recvBuf[MAX_LEN_BUF];
};

#endif

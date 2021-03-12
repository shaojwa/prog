

#ifndef CLIENT_H
#define CLIENT_H


#include "type.h"
#include "resource.h"
#include "sock.h"
#include "cl.h"
#include "pth.h"
#include "proto.h"

#include "frame.h"
#include <windows.h>
#include <tchar.h>
#include <list>


class Client {
public :
    Client();
    ~Client();
    bool init();
    bool release();
    bool connect();
    bool sendReq(request_t *req);

private:
    static uint32_t __stdcall Client::handleUI(void* param);
    static uint32_t __stdcall Client::handleSvc(void* param);

    Cl *m_pCl;
    Pth *m_pthHandleUI;
    Pth *m_pthHandleSvc;
    Frame *m_pFrame;
    Sock *m_skConn;
    Pkt *m_pktRequest;
    char m_szSvcIp[MAX_LEN_IP];
    uint16_t m_nSvcPort;
    std::list<request_t> m_reqList;

    HANDLE m_hEventRequest;
};
#endif
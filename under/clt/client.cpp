

#include "client.h"
#include "config.h"
#include "log.h"

Client::Client(){
    strcpy(m_szSvcIp, "127.0.0.1");
    m_nSvcPort = SVC_CONFIG_LISTEN_PORT;
    m_skConn = new Sock();
    m_pktRequest = new Pkt();
}


Client::~Client() {
}


bool Client::init() {
    if (!Sock::startup()) {
        return false;
    }

    m_pCl = new Cl();
    if (m_pCl == NULL) {
        logline(LOG::LEVEL_ERROR, "create Cl failed.");
        return false;
    }

#ifdef _DEBUG
    m_pCl->attachDbgCon();
#endif

    //m_hWaitEvent = CreateEvent(NULL, FALSE, FALSE, CLT_EVENTNAME_WAIT2WORK);
    //if (m_hWaitEvent == INVALID_HANDLE_VALUE) {
    //    logline(LOG::LEVEL_ERROR, "create event failed.(error = %d)\n", GetLastError());
    //    return false;
    //}

    m_pthHandleUI = new Pth(handleUI);
    if (m_pthHandleUI == NULL) {
        return false;
    }
    m_pthHandleUI->startThread(this);

    m_pthHandleSvc = new Pth(handleSvc);
    if (m_pthHandleSvc == NULL) {
        return false;
    }
    m_pthHandleSvc->startThread(this);

    m_pFrame = new Frame();
    if (m_pFrame == NULL) {
        logline(LOG::LEVEL_ERROR, "create mail frame failed.");
        return false;
    }
    m_pFrame->Create(NULL, CLT_MAINFRAME_TITLE, UI_WNDSTYLE_FRAME, WS_EX_WINDOWEDGE);
    m_pFrame->SetIcon(IDI_ICON);
    m_pFrame->ShowWindow(true);

    logline(LOG::LEVEL_INFO, "handleUI thread id = %d", m_pthHandleUI->getTid());
    logline(LOG::LEVEL_INFO, "handleSvc thread id = %d", m_pthHandleSvc->getTid());

    return true;
}


bool Client::release() {
    if (!Sock::cleanup()) {
        return false;
    }
}


bool Client::connect() {
    if (!m_skConn->connectTo(m_szSvcIp, m_nSvcPort)) {
        return false;
    }
    return true;
}


bool Client::sendReq(request_t * req) {
    m_pktRequest->cleanup();
    m_pktRequest->create(req->module, req->command);
    if (!m_skConn->sendTcp(m_pktRequest->getBuf(), m_pktRequest->getLen())) {
        return false;
    } else {
        return true;
    }
}


uint32_t __stdcall Client::handleUI(void* param) {
    Client * pclient = (Client *)param;
    while (true) {
        ::Sleep(1000);
    }
    return 0;
}


uint32_t __stdcall Client::handleSvc(void* param) {
    HINSTANCE hInst = 0;
    bool connected = false;
    Client * pclient = (Client *)param;
    while (WAIT_OBJECT_0 == WaitForSingleObject(pclient->m_hEventRequest, INFINITE)) {
        while(!pclient->m_reqList.empty()) {
            if (!connected && !pclient->connect()) {
                logline(LOG::LEVEL_ERROR, "connect server failed. retry.");
                ::Sleep(CLT_CONNECT_INTERVAL);
                continue;
            } else {
                connected = true;
                logline(LOG::LEVEL_INFO, "connect server success.");
            }

            request_t pReq = pclient->m_reqList.front();
            if(!pclient->sendReq(&pReq)) {
                connected = false;
                continue;
            }
            pclient->m_reqList.pop_front();
        }
    }
    return 0;
}
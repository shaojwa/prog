
#include "comm.h"
#include "pth.h"
#include "log.h"


Comm::Comm():m_nListenPort(0) {
}


Comm::~Comm() {
}


uint32_t __stdcall Comm::listenClient(void* pParam) {
    Comm *pComm = (Comm *)pParam;
    pComm->m_skListen->listenTcp(pComm->m_nListenPort);
    return 0;
}


uint32_t __stdcall Comm::wait2handlePkt(void* pParam) {
     Comm *pComm = (Comm *)pParam;
     while (WAIT_OBJECT_0 == WaitForSingleObject(pComm->m_hPktEvent, INFINITE)) {
     }
     return 0;
}




bool Comm::init(uint16_t listenPort) {
    m_hPktEvent = CreateEvent(NULL, FALSE, FALSE, NULL);
    if (NULL == m_hPktEvent) {
        logline(LOG::LEVEL_ERROR, "create event failed(error = %u)", GetLastError());
        return false;
    }
    m_skListen = new Sock();
    logline(LOG::LEVEL_INFO, "set listen port = %d", listenPort);
    m_nListenPort = listenPort;
    m_pthListen = new Pth(listenClient);
    if (NULL == m_pthListen) {
        return false;
    }
    if(!m_pthListen->startThread((void *)this)) {
        return false;
    }
    logline(LOG::LEVEL_INFO, "start listen thread (%u)", m_pthListen->getTid());

    m_pthHandle = new Pth(wait2handlePkt);
    if (NULL == m_pthHandle) {
        return false;
    }

    if (!m_pthHandle->startThread((void*)this)) {
        return false;
    }
    logline(LOG::LEVEL_INFO, "start handle thread (%u)", m_pthHandle->getTid());

    return true;
}

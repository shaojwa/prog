
//
// the module communicate with client
//

#ifndef COM_H
#define COM_H

#include "sock.h"
#include "pth.h"
#include "type.h"


class Comm {
public:
    Comm();
    ~Comm();
    bool init(uint16_t listenPort);
    bool listenUdp();
    bool listenTcp();
    static uint32_t __stdcall listenClient(void* pParam);
    static uint32_t __stdcall wait2handlePkt(void* pParam);

private:
    Pth *m_pthListen;
    Pth *m_pthHandle;
    HANDLE m_hPktEvent;

    Sock *m_skListen;
    unsigned short m_nListenPort;

};
#endif
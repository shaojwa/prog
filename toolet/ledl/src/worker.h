

#ifndef WORKER_H
#define WORKER_H

#include "config.h"
#include <windows.h>

enum WORKER_STATE {
    WORKER_STATE_IDLE = 0,
    WORKER_STATE_FIND = 1,
    WORKER_STATE_COPY = 2
};

class CWorker {
public:
    CWorker();
    ~CWorker();
    void attachEvent(HANDLE hExtractEvent);
    int createWaitThread();
    int createWorkThread();
    void setExtractType(EExtratType type);
    int getState();
    HANDLE getWaitEvent();
    int attachConfig(CConfig *);
    void setHWND(const HWND);
    HWND getHWND();

private:
    static unsigned WINAPI thfWait(void *);
    static unsigned WINAPI thfWork(void *);

    HANDLE m_hWaitThread;
    HANDLE m_hWorkThread;
    HANDLE m_hExtractEvent;
    unsigned m_tidWait;
    unsigned m_tidWork;
    int m_nWorkerState;
    CConfig *m_pConfig;
    HWND m_hwnd;

};


#endif 
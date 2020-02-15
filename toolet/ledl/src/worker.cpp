

#include "worker.h"

#include <stdio.h>
#include <process.h>


CWorker::CWorker():
m_hWaitThread(INVALID_HANDLE_VALUE),
m_hWorkThread(INVALID_HANDLE_VALUE),
m_tidWait(0),m_tidWork(0),
m_nWorkerState(WORKER_STATE_IDLE),
m_hwnd(NULL){
}

CWorker::~CWorker() {
}


int CWorker::attachConfig(CConfig *pConfig) {
    if(NULL == pConfig) {
        return 1;
    }
    m_pConfig = pConfig;
    return 0;
}


void CWorker::attachEvent(HANDLE hExtractEvent) {
    m_hExtractEvent = hExtractEvent;
}


int CWorker::getState() {
    return m_nWorkerState;
}


HANDLE CWorker::getWaitEvent(){
    return m_hExtractEvent;
}



unsigned WINAPI CWorker::thfWait(void* param) {
    CWorker * worker = (CWorker *)param;
    while (WAIT_OBJECT_0 == WaitForSingleObject(worker->getWaitEvent(), INFINITE)) {
        printf("INFO: event set\n");
        int state = worker->getState();
        if (WORKER_STATE_IDLE == state) {
            worker->createWorkThread();
        } else if (WORKER_STATE_FIND == state) {
        } else if (WORKER_STATE_COPY == state) {
        } else {
        }
    }
    return 0;
}


int CWorker::createWaitThread() {
    m_hWaitThread = (HANDLE) _beginthreadex(
        NULL, 0, thfWait,(VOID *) this, 0, &m_tidWait);
    if (INVALID_HANDLE_VALUE == m_hWaitThread) {
        printf("FATAL: create wait_thread failed(error = %d)\n", GetLastError());
        exit(-1);
    }
    printf("tid_wait = %d\n", m_tidWait);
    return 0;
}


unsigned WINAPI CWorker::thfWork(void* param) {
    CWorker * pWorker = (CWorker *)param;
    HINSTANCE hInst = 0;
     TCHAR szParam[MAX_PATH] = {0};
    if (EXTRACT_TYPE_AUTO == pWorker->m_pConfig->getExtractType()) {
         _tcscpy(szParam, _T("le_auto.bat"));
    } else {
        LPCTSTR pPattern = pWorker->m_pConfig->getPattern();
        LPCTSTR pSrcDir = pWorker->m_pConfig->getSrc();
        LPCTSTR pDstDir = pWorker->m_pConfig->getDst();
        _stprintf(szParam, _T("le_cust.bat \"%s\" \"%s\" \"%s\""), pPattern, pSrcDir, pDstDir);
    }

    hInst = ShellExecute(NULL, _T("open"), szParam, NULL, NULL, SW_HIDE);
    if((int)hInst <= 32) {
        printf("ERROR: ShellExecute() failed with %u\n", hInst);
    }
    pWorker->m_pConfig->setProgress(100);
    HWND hwnd = pWorker->getHWND();
    if (hwnd) {
        ::PostMessage(hwnd, USER_MSG_TASK_STATE, TASK_TYPE_SYS_PROCESSES, TASK_STATE_FINISHED);
    }
    return 0;
}

int CWorker::createWorkThread(){
    m_hWorkThread = (HANDLE) _beginthreadex(
        NULL, 0, thfWork,(VOID *) this, 0, &m_tidWork);
    if (INVALID_HANDLE_VALUE == m_hWorkThread) {
        printf("FATAL: create work thread failed(error = %d)\n", GetLastError());
        exit(-1);
    }
    printf("tid_find = %d\n", m_tidWork);
    return 0;
}


void CWorker::setHWND(const HWND hwnd) {
    m_hwnd = hwnd;
}


HWND CWorker::getHWND() {
    return m_hwnd;
}

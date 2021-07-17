
#include "resource.h"
#include "frame.h"
#include "worker.h"
#include "config.h"

#define EVENT_NAME_AUTO_EXTRACT   _T("le_extract_event")



int attchDbgCon() {
    if (AttachConsole(-1)) {
        freopen("conout$", "r+t", stdout);
        freopen("conout$", "r+t", stderr);
        return 0;
    }
    return GetLastError();
}


int detachDbgCon() {
    if (FreeConsole()) {
        return 0;
    } else {
        return GetLastError();
    }
}


int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow) {
    
    DWORD dwError = 0;
    CConfig *pCfg = NULL;
    HANDLE hExtractEvent = NULL;

    printf("\ncurrent thread id = %d\n", GetCurrentThreadId());
    attchDbgCon();
    pCfg = new CConfig();

    HINSTANCE h = hInstance;
    CPaintManagerUI::SetInstance(hInstance);
    CPaintManagerUI::SetResourcePath(CPaintManagerUI::GetInstancePath());
    CPaintManagerUI::SetResourceZip(_T("res.zip"));

    HRESULT Hr = ::CoInitialize(NULL);
    if( FAILED(Hr) ) return 0;

    Frame * pFrame = new Frame();
    if (NULL == pFrame) {
        return 0;
    }

    pFrame->Create(NULL, _T("LogExtractor"), UI_WNDSTYLE_FRAME, WS_EX_WINDOWEDGE);
    pFrame->SetIcon(IDI_ICON);
    pFrame->attachConfig(pCfg);
    pFrame->ShowWindow(true);

    hExtractEvent = CreateEvent(NULL, FALSE, FALSE, EVENT_NAME_AUTO_EXTRACT);
    if (hExtractEvent == INVALID_HANDLE_VALUE) {
        dwError = GetLastError();
        printf("ERROR: create event failed.(error = %d)\n", dwError);
        exit(-1);
    }

    pFrame->attachEvent(hExtractEvent);

    CWorker *pWorker = new CWorker();
    pWorker->attachEvent(hExtractEvent);
    pWorker->attachConfig(pCfg);
    pWorker->setHWND(pFrame->GetHWND());
    if (0 != pWorker->createWaitThread()) {
        printf("ERROR: create thread to wait event failed\n");
        exit(-1);
    }

    CPaintManagerUI::MessageLoop();
    ::CoUninitialize();
    return 0;
}
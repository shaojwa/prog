

#include "config.h"
#include "client.h"
#include "log.h"
#include "worker.h"

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance,
                   LPSTR lpCmdLine, int nCmdShow)
{
    HINSTANCE h = hInstance;
    CPaintManagerUI::SetInstance(hInstance);
    LPCTSTR path = CPaintManagerUI::GetInstancePath();
    CPaintManagerUI::SetResourcePath(CPaintManagerUI::GetInstancePath());

    Client *pClient = new Client();
    if (!pClient->init()) {
        logline(LOG::LEVEL_ERROR, "client init failed.");
        return false;
    }

    CPaintManagerUI::MessageLoop();
    return 0;
}

#ifndef SVC_H
#define SVC_H

#include "sock.h"
#include "config.h"

#include <windows.h>

bool svcExists(void);
bool svcInstall(void);
bool svcInit(DWORD dwArgc, LPCTSTR *lpszArgv);
bool svcStartup(VOID);
int  setListenPort(unsigned short port);
VOID reportStatus(DWORD dwCurrentState, DWORD dwWin32ExitCode, DWORD dwWaitHint);
VOID WINAPI ctrlHandler(DWORD);

#endif


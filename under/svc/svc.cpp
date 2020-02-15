

#include "config.h"
#include "svc.h"
#include "mon.h"
#include "comm.h"

#include "log.h"
#include "pth.h"

#include <windows.h>
#include <tchar.h>

#include <iostream>
using namespace std;

SERVICE_STATUS gStatus;
SERVICE_STATUS_HANDLE ghStatus;
SERVICE_TABLE_ENTRY gSvcTable[2];
HANDLE ghStopEvent;

Comm *gpComm = NULL;
Mon *gpMon = NULL;

//
// Purpose: 
//   Called by SCM whenever a control code is sent to the service
//   using the ControlService function.
//
// Parameters:
//   dwCtrl - control code
// 
// Return value:
//   None
//
VOID WINAPI ctrlHandler(DWORD dwCtrl) {
    // Handle the requested control code.
    logline(LOG::LEVEL_INFO, "ctrl tid = %d", GetCurrentThreadId());
    switch(dwCtrl) 
    {  
    case SERVICE_CONTROL_STOP: 
        reportStatus(SERVICE_STOP_PENDING, NO_ERROR, 0);
        // Signal the service to stop.
        SetEvent(ghStopEvent);
        reportStatus(gStatus.dwCurrentState, NO_ERROR, 0);
        return;

    case SERVICE_CONTROL_INTERROGATE: 
        break; 

    default: 
        break;
    }
}


VOID reportStatus( DWORD dwCurrentState,
                  DWORD dwWin32ExitCode,
                  DWORD dwWaitHint)
{
    static DWORD dwCheckPoint = 1;

    // Fill in the SERVICE_STATUS structure.
    gStatus.dwCurrentState = dwCurrentState;
    gStatus.dwWin32ExitCode = dwWin32ExitCode;
    gStatus.dwWaitHint = dwWaitHint;

    logline(LOG::LEVEL_INFO, "current status = %d.", dwCurrentState);
    if (dwCurrentState == SERVICE_START_PENDING) {
        gStatus.dwControlsAccepted = 0;
    } else {
        gStatus.dwControlsAccepted = SERVICE_ACCEPT_STOP;
    }

    if ((dwCurrentState == SERVICE_RUNNING) || (dwCurrentState == SERVICE_STOPPED)) {
        logline(LOG::LEVEL_INFO, "set checkpoint to 0.");
        gStatus.dwCheckPoint = 0;
    } else {
        gStatus.dwCheckPoint = dwCheckPoint++;
    }

    // Report the status of the service to the SCM.
    if (!SetServiceStatus(ghStatus, &gStatus)) {
        DWORD dwError = GetLastError();
        logline(LOG::LEVEL_ERROR, "set status failed. (error = %d)", dwError);
    }
}


//
// Purpose: 
//   Entry point for the service
//
// Parameters:
//   dwArgc - Number of arguments in the lpszArgv array
//   lpszArgv - Array of strings. The first string is the name of
//     the service and subsequent strings are passed by the process
//     that called the StartService function to start the service.
// 
// Return value:
//   None.
//
VOID WINAPI svcMain(DWORD dwArgc, LPCTSTR * lpszArgv)
{
    logline(LOG::LEVEL_INFO, "svcMain, tid = %d.", GetCurrentThreadId());
    ghStatus = RegisterServiceCtrlHandler(SVC_CONFIG_SERVICE_NAME, ctrlHandler);
    if (INVALID_HANDLE_VALUE == ghStatus) {
        exit(-1);
    }
    gStatus.dwServiceType = SERVICE_WIN32_SHARE_PROCESS;
    gStatus.dwServiceSpecificExitCode = 0;

    //Report initial status to SCM
    reportStatus(SERVICE_START_PENDING, NO_ERROR, 1000);

    //Perform service-specific initialization and work
    if (!svcInit(dwArgc, lpszArgv)) {
        logline(LOG::LEVEL_ERROR, "init service failed.");
        reportStatus(SERVICE_STOPPED, NO_ERROR, 0);
        exit(-1);
    }

    //Report running status when initialization is complete.
    logline(LOG::LEVEL_ERROR, "set status to running.");
    reportStatus(SERVICE_RUNNING, NO_ERROR, 1000);

    gpComm = new Comm();
    if (!gpComm->init(SVC_CONFIG_LISTEN_PORT)) {
        logline(LOG::LEVEL_ERROR, "init com module failed.");
        reportStatus(SERVICE_STOPPED, NO_ERROR, 0);
    }

    gpMon = new Mon();
    if (!gpMon->init()) {
        logline(LOG::LEVEL_ERROR, "init mon module failed.");
        reportStatus(SERVICE_STOPPED, NO_ERROR, 0);
    }


    while(true) {
        // Check whether to stop the service.
        logline(LOG::LEVEL_INFO, "waiting for stop event.");
        WaitForSingleObject(ghStopEvent, INFINITE);
        logline(LOG::LEVEL_INFO, "set status to stopped.");
        reportStatus( SERVICE_STOPPED, NO_ERROR, 0 );
    }
}


//
// launch the service from SCM
//
bool svcStartup(void)
{
    BOOL ret;
    DWORD dwError;
    gSvcTable[0].lpServiceName = SVC_CONFIG_SERVICE_NAME;
    gSvcTable[0].lpServiceProc = (LPSERVICE_MAIN_FUNCTION)svcMain;
    gSvcTable[1].lpServiceName = NULL;
    gSvcTable[1].lpServiceProc = NULL;

    logline(LOG::LEVEL_INFO, "dispatcher. tid = %d", GetCurrentThreadId());
    ret = StartServiceCtrlDispatcher(gSvcTable);
    if (!ret) {
        dwError = GetLastError();
        if (ERROR_FAILED_SERVICE_CONTROLLER_CONNECT == dwError) {
            return false;
        } else if (ERROR_SERVICE_ALREADY_RUNNING == dwError ) {
            return false;
        } else if (ERROR_INVALID_DATA == dwError) {
            return false;
        }
    }
    logline(LOG::LEVEL_INFO, "main thread quit.");
    return true;
}


bool svcInit(DWORD dwArgc, LPCTSTR *lpszArgv) {
    if(!Sock::startup()) {
        return false;
    }
    ghStopEvent = CreateEvent( NULL, TRUE, FALSE, NULL);
    if (ghStopEvent == NULL) {
        return false;
    }
    return true;
}


bool svcRelease() {
    if(!Sock::cleanup()) {
        return false;
    }
    return true;
}


bool svcExists()
{
    DWORD errcode;
    SC_HANDLE hscm = OpenSCManager(NULL, NULL, SC_MANAGER_CREATE_SERVICE);
    if (NULL == hscm) {
        errcode = GetLastError();
        return false;
    }

    SC_HANDLE hsrv = OpenService(hscm, SVC_CONFIG_SERVICE_NAME, GENERIC_READ);
    if (NULL != hsrv) {
        return true;
    }
    return false;
}


bool svcInstall()
{
    DWORD errcode;
    TCHAR szPath[MAX_PATH];

    if(svcExists()) {
        return true;
    }

    if(!GetModuleFileName(NULL, szPath, MAX_PATH)) {
        return false;
    }

    SC_HANDLE hscm = OpenSCManager(NULL, NULL, SC_MANAGER_CREATE_SERVICE);
    if (NULL == hscm) {
        errcode = GetLastError();
        return false;
    }

    SC_HANDLE hsrv = CreateService(
        hscm, 
        SVC_CONFIG_SERVICE_NAME,
        SVC_CONFIG_DISPLAY_NAME, 
        SERVICE_ALL_ACCESS, 
        SERVICE_WIN32_SHARE_PROCESS,
        SERVICE_DEMAND_START,
        SERVICE_ERROR_NORMAL,
        szPath,
        NULL, NULL, NULL, NULL, NULL);

    if (NULL == hsrv)
    {
        errcode = GetLastError();
        return false;
    }
    return true;
}

//
// description: get the status of service process
//
DWORD getSvcStatus(LPCTSTR srvname)
{
    int ret = 0;
    unsigned errcode = 0;
    SERVICE_STATUS_PROCESS status;
    DWORD bytesNeed;

    SC_HANDLE hscm = OpenSCManager(NULL, NULL, SC_MANAGER_CONNECT);
    SC_HANDLE hsrv = OpenService(hscm, srvname, SERVICE_QUERY_STATUS);
    if (hsrv == NULL) {
        CloseServiceHandle(hscm);
        errcode = GetLastError();
        return 0;
    }
    ret = QueryServiceStatusEx(hsrv, SC_STATUS_PROCESS_INFO, (LPBYTE)&status,
        sizeof(SERVICE_STATUS_PROCESS), &bytesNeed);
    if (!ret)
    {
        CloseServiceHandle(hscm);
        CloseServiceHandle(hsrv);
        return 0;
    }

    CloseServiceHandle(hscm);
    CloseServiceHandle(hsrv);
    return status.dwCurrentState;
}

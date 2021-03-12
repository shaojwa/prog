

#include "pth.h"
#include <windows.h>
#include <stdio.h>

#include <process.h>
#include <psapi.h>
#include <tchar.h>

Pth::Pth(threadfunc_t func): m_threadFunc(func) {
}

bool Pth::startThread(void * pParam) {
    if (NULL == m_threadFunc) {
        return false;
    }

    m_hThread = (HANDLE)_beginthreadex(NULL, 0, m_threadFunc, pParam, 0, &m_nThreadId);
    if (0 == m_hThread)
    {
        return false;
    }
    return true;
}

uint32_t Pth::getTid(){
    return m_nThreadId;
}

int Pth::getImageByPid(unsigned pid, LPTSTR image, int bufLen)
{
    unsigned errcode = 0;
    HANDLE hProcess;
    hProcess = OpenProcess(PROCESS_QUERY_INFORMATION, FALSE, pid);

    if (NULL == hProcess)
    {
        errcode = GetLastError();
        return errcode;
    }

    DWORD ret = GetProcessImageFileName(hProcess, image, bufLen);
    if (0 == ret)
    {
        errcode = GetLastError();
        CloseHandle(hProcess);
        return errcode;
    }
    CloseHandle(hProcess);
    return 0;
}


int Pth::getPidByImage(LPTSTR imageName)
{
    int errcode = 0;
    int ret = 0;

    /* guess the number of process is less then 32 */
    DWORD processCount = 32;
    DWORD *pProcesses = NULL;
    DWORD cb = processCount * sizeof(DWORD);
    pProcesses = (DWORD *)malloc(cb);
    if (NULL == pProcesses) {
        errcode = errno;
        return -1;
    }

    DWORD bytesRet;
    
    ret = EnumProcesses(pProcesses, processCount * sizeof(DWORD), &bytesRet);
    if (!ret) {
        errcode = GetLastError();
        return -1;
    }

    while (cb == bytesRet)
    {
        free(pProcesses);
        processCount *= 2;
        cb = processCount * sizeof(DWORD);
        pProcesses = (DWORD *)malloc(cb);
        ret = EnumProcesses(pProcesses, processCount * sizeof(DWORD), &bytesRet);
        if (!ret)
        {
            errcode = GetLastError();
            return -1;
        }
    }

    processCount = bytesRet / sizeof(DWORD);

    HANDLE hProc;
    DWORD targetPid = 0;
    TCHAR image[MAX_PATH];
  
    for (DWORD i = 0; i < processCount; i++)
    {
        DWORD pid = *(pProcesses + i);
        hProc = OpenProcess(PROCESS_QUERY_INFORMATION, FALSE, pid);
        if (NULL == hProc)
        {
            errcode = GetLastError();
            continue;
        }
        DWORD size= _countof(image);
        DWORD ret = GetProcessImageFileName(hProc, image, size);
        if (0 == ret) {
            errcode = GetLastError();
        }
        CloseHandle(hProc);

        if (_tcscmp(image, imageName) == 0) {
            targetPid = pid;
            break;
        }
    }
    return targetPid;
}


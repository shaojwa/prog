

#ifndef THREAD_H
#define THREAD_H

#include "type.h"
#include <windows.h>
#include <tchar.h>

#define DllExport __declspec( dllexport )

typedef unsigned int ( __stdcall * threadfunc_t)( void * );

class DllExport Pth {
public:
    Pth(threadfunc_t func);
    ~Pth();
    bool setThreadFunc(threadfunc_t threadFunc);
    bool startThread(void * pParam);
    uint32_t getTid(void);
    int getSvcStatus(LPCTSTR srvname);
    static int getPidByImage(LPTSTR imageName);
    static int getImageByPid(unsigned pid, LPTSTR image, int bufLen);

private:
    threadfunc_t m_threadFunc;
    uint32_t m_nThreadId;
    HANDLE m_hThread;
};

#endif 
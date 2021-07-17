

#ifndef CL_H
#define CL_H

#include <windows.h>
#include <tchar.h>

#define DllExport __declspec( dllexport )


#define PIPE_BUFSIZE 32 

typedef struct {
    OVERLAPPED oOverlap;
    HANDLE hPipeInst;
    TCHAR chRequest[PIPE_BUFSIZE];
    DWORD cbRead;
    TCHAR chReply[PIPE_BUFSIZE];
    DWORD cbToWrite; 
} PIPEINST, *LPPIPEINST; 

typedef enum {
    NS_NONE        = 0,
    NS_EXIT        = 1,
    NS_CONTINUE    = 2
} NEXT_STEP;

class DllExport Cl
{
public:
    Cl();
    ~Cl();

    /* for server*/
    static Cl& getInst();

    /* return values: 0: error, other: number of arguments */
    int parseArgs(void);

    int createPipe(LPCTSTR lpPipename);
    int startListen(void);
    
    bool isUnique();
    static bool StartListenThread(LPCTSTR pipename);

    /* for client*/
    static HANDLE openPipe(LPCTSTR pipename);
    static bool sendCmd(LPCTSTR cmd);
    static bool closePipe();

    /* for debug */
    int attachDbgCon();
    int detachDbgCon();

private:
    void release();
    static DWORD WINAPI listenProc(LPVOID lpParam);
    int connectPipe();

/*    static BOOL ConnectPipe(HANDLE hPipe, LPOVERLAPPED lpo);
    static VOID WINAPI CompletedWriteRoutine(
        DWORD dwErr, DWORD cbWritten, LPOVERLAPPED lpOverLap);
    static VOID WINAPI CompletedReadRoutine(
        DWORD dwErr, DWORD cbBytesRead, LPOVERLAPPED lpOverLap);
    static VOID DisconnectAndClose(LPPIPEINST lpPipeInst)*/;

    static bool m_inited;
    static Cl* m_instance;

    LPWSTR* m_szArglist;
    HANDLE m_hPipe;
    DWORD m_result;
    TCHAR m_pipename[MAX_PATH];
    DWORD m_timeout;

    LPPIPEINST m_lpPipeInst;
    OVERLAPPED m_overlap;
};

#endif 
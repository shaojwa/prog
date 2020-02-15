

#include "cl.h"
#include <stdio.h>


bool Cl::m_inited = false;
Cl * Cl::m_instance = NULL;

Cl::Cl():m_szArglist(NULL) {
    memset(m_pipename, 0, sizeof(m_pipename));
}

Cl::~Cl() {
    LocalFree(m_szArglist);
}

Cl& Cl::getInst()
{
    if (!m_inited)
    {
        m_instance = new Cl();
        m_inited = true;
    }
    return *m_instance;
}

int Cl::attachDbgCon() {
    if (::AttachConsole(-1)) {
        freopen("conout$", "r+t", stdout);
        freopen("conout$", "r+t", stderr);
        return 0;
    } else {
        return GetLastError();
    }
}


int Cl::detachDbgCon() {
    if (::FreeConsole()) {
        return 0;
    } else {
        return GetLastError();
    }
}


int Cl::createPipe(LPCTSTR lpPipename = NULL) {
    int errcode = 0;
    int ret = 0;
    TCHAR szFileName[MAX_PATH] = {0};

    if (lpPipename == NULL) {
        ret = GetModuleFileName(NULL, szFileName, MAX_PATH);
        if (0 == ret) {
            return -1;
        }
        _tcscpy(m_pipename, szFileName);
    }
    
    m_hPipe = CreateNamedPipe(
        m_pipename,
        PIPE_ACCESS_DUPLEX |FILE_FLAG_OVERLAPPED,
        PIPE_TYPE_MESSAGE | PIPE_READMODE_MESSAGE | PIPE_WAIT,
        PIPE_UNLIMITED_INSTANCES,
        PIPE_BUFSIZE * sizeof(TCHAR),
        PIPE_BUFSIZE * sizeof(TCHAR),
        m_timeout,
        NULL);

    if (m_hPipe == INVALID_HANDLE_VALUE) {
        errcode = GetLastError();
    }
    return errcode;
}

int Cl::connectPipe() {

    DWORD dwError = 0;
    BOOL bConnected = ConnectNamedPipe(m_hPipe, &m_overlap);
    dwError = GetLastError();
    if (dwError != ERROR_IO_PENDING && dwError != ERROR_PIPE_CONNECTED) {
        return -1;
    }
    if (dwError == ERROR_IO_PENDING) {
        return 0;
    } else if (dwError == ERROR_PIPE_CONNECTED){
        SetEvent(m_overlap.hEvent);
        return 0;
    } else {
        return -1;
    }
}

bool Cl::isUnique() {
    HANDLE pipe = CreateFile(m_pipename, GENERIC_READ | GENERIC_WRITE, 
        0, NULL, OPEN_EXISTING, 0, NULL); 
    if (pipe == INVALID_HANDLE_VALUE) {
        CloseHandle(pipe);
        return true;
    }
    CloseHandle(pipe);
    return false;
}


int Cl::parseArgs()
{
    int nArgs = 0;
    LPTSTR line = GetCommandLine();
    m_szArglist = CommandLineToArgvW(line, &nArgs);
    if (NULL == m_szArglist) {
        return 0;
    }
    return nArgs;
}


int Cl::startListen()
{
    DWORD dwError = 0;
    HANDLE hThread = NULL;
    hThread = CreateThread(NULL, 0, listenProc, NULL, 0, NULL);
    if (NULL == hThread) {
        dwError = GetLastError();
    }
    return dwError;
}


DWORD Cl::listenProc(LPVOID lpParam)
{
    Cl * pcl = (Cl*)lpParam;

    DWORD dwError = 0;
    

    /* create an event to notice */
    HANDLE hConnectEvent = CreateEvent(NULL, TRUE, TRUE, NULL);

    if (NULL == hConnectEvent)
    {
        dwError = GetLastError();
        return dwError;
    }
    pcl->m_overlap.hEvent = hConnectEvent;
    BOOL fPendingIO = pcl->connectPipe();


    while (true)
    {
        /* return when client connection or complete read and write */  
        DWORD dwWait = WaitForSingleObjectEx(hConnectEvent, INFINITE, TRUE);
        if (0 == dwWait) {
            if (fPendingIO) {
                DWORD cbRet; 
                BOOL fSuccess = GetOverlappedResult(
                    pcl->m_hPipe, &(pcl->m_overlap), &cbRet, FALSE);

                if (!fSuccess) 
                {
                    dwError = GetLastError();
                    break;
                }
            }

            pcl->m_lpPipeInst = (LPPIPEINST) GlobalAlloc( GPTR, sizeof(PIPEINST));
            if (pcl->m_lpPipeInst == NULL) 
            {
                dwError = GetLastError();
                return 0;
            }

            /*
            原有的管道句柄_pipe保存在lpPipeInst以在完成例程中使用。
            LPPIPEINST结构的第一项是OVERLAPPED。所以可对lpPipeInst进行强转。
            之后client的所有请求都通过完成函数相互调用处理不再用到_pipe。
            */

            pcl->m_lpPipeInst->hPipeInst = pcl->m_hPipe;
            pcl->m_lpPipeInst->cbToWrite = 0;
            //CompletedWriteRoutine(0, 0, (LPOVERLAPPED) lpPipeInst);
            /*创建一个新的管道实例以处理下一个客户端的连接请求。*/
            //fPendingIO = CreateAndConnectInstance(&oConnect);

        } else if (WAIT_IO_COMPLETION == dwWait) {
            continue;
        } else {
            dwError = GetLastError();
            break;
        }
    }
    return dwError;
}


/*
服务端进程创建命名管道并主动连接到管道。
如果客户端没有连接到管道则返回成功。
如果客户端已经连到管道上则返回失败。
*/
// BOOL CmdUtil::CreateAndConnectInstance(LPOVERLAPPED lpoOverlap)
// {
//     m_pipe = CreateNamedPipe( 
//         m_pipename,
//         PIPE_ACCESS_DUPLEX |FILE_FLAG_OVERLAPPED,
//         PIPE_TYPE_MESSAGE | PIPE_READMODE_MESSAGE | PIPE_WAIT,
//         PIPE_UNLIMITED_INSTANCES,
//         PIPE_BUFSIZE * sizeof(TCHAR),
//         PIPE_BUFSIZE * sizeof(TCHAR),
//         m_timeout,
//         NULL);
// 
//     if (m_pipe == INVALID_HANDLE_VALUE) 
//     {
//         LOG(LL_INFO, "error(%d):CreateNamedPipe() failed", GetLastError()); 
//         return FALSE;
//     }
//     else
//     {
//         LOG(LL_INFO, "ok: CreateNamedPipe().");
//         LOG(LL_INFO, "**** _pipe = 0x%p ****", m_pipe);
//         
//     }
// }


// BOOL CmdUtil::ConnectPipe(HANDLE hPipe, LPOVERLAPPED lpo)
// {
//     /*
//     调用ConnectNamedPipe进入等待客户端进程连接的状态。
//     因为是异步操作所以ConnectNamedPipe应该立即返回0
//     并且GetLastError() = ERROR_IO_PENDING.
//     */
//     BOOL fConnected = ConnectNamedPipe(hPipe, lpo);
//     LOG(LL_INFO, "info: ConnectNamedPipe() returns: %d.", fConnected);
// 
//     if (fConnected)
//     {
//         LOG(LL_INFO, "error(%d): ConnectNamedPipe failed", GetLastError()); 
//         return 0;
//     }
// 
//     BOOL fPendingIO = FALSE;
//     switch (GetLastError()) 
//     {
//     case ERROR_IO_PENDING: 
//         {
//             fPendingIO = TRUE; 
//             break;
//         }
//     case ERROR_PIPE_CONNECTED:
//         {
//             LOG(LL_INFO, "SetEvent");
//             if (SetEvent(lpo->hEvent))
//                 break;
//         }
//     default:
//         {
//             LOG(LL_INFO, "error(%d): ConnectNamedPipe failed", GetLastError());
//             return 0;
//         }
//     }
//     return fPendingIO;
// }


///*
//* 当写操作完成之后或者当客户端例程连接到管道时调用本例程
//*/
//VOID CmdUtil::CompletedWriteRoutine(DWORD dwErr, DWORD cbWritten, 
//                                    LPOVERLAPPED lpOverLap) 
//{
//    LOG(LL_INFO, "dwErr = %d, cdWritten = %d", dwErr, cbWritten);
//    BOOL fRead = FALSE;
//    LPPIPEINST lpPipeInst = (LPPIPEINST) lpOverLap;
//    LOG(LL_INFO, "pipe = 0x%p", lpPipeInst->hPipeInst);
//    if ((dwErr == 0) && (cbWritten == lpPipeInst->cbToWrite))
//    {
//        fRead = ReadFileEx(
//            lpPipeInst->hPipeInst,
//            lpPipeInst->chRequest,
//            PIPE_BUFSIZE * sizeof(TCHAR),
//            (LPOVERLAPPED) lpPipeInst,
//            (LPOVERLAPPED_COMPLETION_ROUTINE)CompletedReadRoutine);
//    }
//    if (!fRead)
//    {
//        LOG(LL_INFO, "error(%d): ReadFileEx() fail.", GetLastError());
//        DisconnectAndClose(lpPipeInst);
//    }
//    else
//    {
//        /*调用ReadFileEx返回成功也需要查看是否有别的需要注意的消息*/
//        DWORD lastErr = GetLastError();
//        if (ERROR_SUCCESS != lastErr && ERROR_IO_PENDING != lastErr)
//        {
//            LOG(LL_INFO, "ReadFileEx() success but GLE = %d", GetLastError());
//        }
//    }
//}
//
//
//VOID  CmdUtil::CompletedReadRoutine(DWORD dwErr, DWORD cbBytesRead,
//                                   LPOVERLAPPED lpOverLap)
//{
//    LOG(LL_INFO, "dwErr = %d, cbBytesRead = %d", dwErr, cbBytesRead);
//    BOOL fWrite = FALSE;
//    LPPIPEINST lpPipeInst = (LPPIPEINST) lpOverLap;
//    LOG(LL_INFO, "pipe = 0x%p", lpPipeInst->hPipeInst);
//
//    if ((dwErr == 0) && (cbBytesRead != 0))
//    {
//        LOGT(LL_INFO, _T("request = %s"), lpPipeInst->chRequest);
//        if (0 == _tcscmp(_T("-exit"), lpPipeInst->chRequest))
//        {
//            LOG(LL_INFO, "guard exit: [ok]");
//            exit(0);
//        }
//
//        *((DWORD *)(lpPipeInst->chReply)) = 0x2104;
//        lpPipeInst->cbToWrite = sizeof(DWORD);
//
//        fWrite = WriteFileEx(
//            lpPipeInst->hPipeInst,
//            &(lpPipeInst->chReply),
//            lpPipeInst->cbToWrite,
//            (LPOVERLAPPED) lpPipeInst,
//            (LPOVERLAPPED_COMPLETION_ROUTINE) CompletedWriteRoutine); 
//    }
//    if (! fWrite)
//    {
//        LOG(LL_INFO, "error(%d): WriteFileEx() fail.", GetLastError());
//        DisconnectAndClose(lpPipeInst);
//    }
//    else
//    {
//        /*调用WriteFileEx返回成功也需要查看是否有别的需要注意的消息*/
//        DWORD lastErr = GetLastError();
//        if (ERROR_SUCCESS != lastErr && ERROR_IO_PENDING != lastErr)
//        {
//            LOG(LL_INFO, "WriteFileEx() success but GLE = %d", GetLastError());
//        }
//    }
//}
//
///*
//发生错误或者客户端关闭管道时调用
//*/
//VOID CmdUtil::DisconnectAndClose(LPPIPEINST lpPipeInst)
//{
//    LOG(LL_INFO, "lpPipeInst = 0x%p", lpPipeInst);
//    if (!DisconnectNamedPipe(lpPipeInst->hPipeInst))
//    {
//        LOG(LL_INFO, "error(%d): DisconnectNamedPipe failed", GetLastError());
//    }
//    if (NULL != lpPipeInst)
//    {
//        if (!CloseHandle(lpPipeInst->hPipeInst))
//        {
//            LOG(LL_INFO, "error(%d): close handle fail.", GetLastError());
//        }
//        GlobalFree(lpPipeInst);
//    }
//}
//
//
//void CmdUtil::Release()
//{
//    delete this;
//    m_instance = NULL;
//    m_inited = false;
//}
//
//
///************************************************************************/
///* 客户端例程
///************************************************************************/
//

//
//BOOL CmdUtil::SendCmdRequest(LPCTSTR cmd)
//{
//    DWORD  cbRead, cbToWrite, cbWritten, dwMode; 
//    dwMode = PIPE_READMODE_MESSAGE; 
//    TCHAR recv[PIPE_BUFSIZE];
//    BOOL fSuccess = SetNamedPipeHandleState(m_pipe, &dwMode, NULL, NULL);  
//    if (!fSuccess)
//    {
//        LOG(LL_INFO, "error(%d): SetNamedPipeHandleState() failed", GetLastError());
//        return FALSE;
//    }
//
//    /*向管道的服务端发送命令 */
//    cbToWrite = (lstrlen(cmd) + 1) * sizeof(TCHAR);
//    LOGT(LL_INFO, _T("Sending %d byte message: [%s]"), cbToWrite, cmd); 
//    fSuccess = WriteFile(m_pipe, cmd, cbToWrite, &cbWritten, NULL);
//    if ( !fSuccess)
//    { 
//        LOG(LL_INFO, "WriteFile to pipe failed. GLE = %d", GetLastError()); 
//        return FALSE;
//    }
//    do
//    {
//        fSuccess = ReadFile(m_pipe, recv, PIPE_BUFSIZE * sizeof(TCHAR),
//            &cbRead, NULL);
//        if (!fSuccess && GetLastError() != ERROR_MORE_DATA)
//            break;
//        LOG(LL_INFO, "cbRead = %d, responce: 0x%x", cbRead, *(DWORD*)recv);
//    } while ( !fSuccess);
//
//    return TRUE;
//}
//
//
//BOOL CmdUtil::ClosePipe(void)
//{
//    if (!CloseHandle(m_pipe))
//    {
//        LOG(LL_INFO, "error(%d): CloseHandle() failed", GetLastError());
//        return FALSE;
//    }
//    return TRUE;
//}
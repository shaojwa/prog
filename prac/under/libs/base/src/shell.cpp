
#include "shell.h"

#include <stdio.h>
#include <process.h>
#include <shellapi.h>

bool Shell::copyFile(LPCTSTR from, LPCTSTR to)
{
    SHFILEOPSTRUCT FileOp;
    ZeroMemory((void*)&FileOp,sizeof(SHFILEOPSTRUCT));


    TCHAR ToBuf[MAX_PATH];
    TCHAR FromBuf[MAX_PATH];

    ZeroMemory(ToBuf, sizeof(ToBuf));
    ZeroMemory(FromBuf, sizeof(FromBuf));

    lstrcpy(FromBuf, from);
    lstrcpy(ToBuf, to);


    FileOp.fFlags = FOF_NOCONFIRMATION;
    FileOp.hNameMappings = NULL;
    FileOp.hwnd = HWND_DESKTOP;
    FileOp.lpszProgressTitle = NULL;
    FileOp.pFrom = FromBuf;
    FileOp.pTo = ToBuf;
    FileOp.wFunc = FO_COPY;
    return  SHFileOperation(&FileOp) == 0;
}

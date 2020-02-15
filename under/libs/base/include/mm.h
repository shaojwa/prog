

#ifndef UDX_COMMON_MEM_H_
#define UDX_COMMON_MEM_H_

#include <windows.h>
#include <tchar.h>
#include <stdlib.h>
#include <stdio.h>

class MmLeak
{
    static BOOL Check(PTCHAR logfile);
};

void mm_check_addr(void);

#endif 
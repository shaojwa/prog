

#ifndef _MMLEAK_H_
#define _MMLEAK_H_

//#define _CRTDBG_MAP_ALLOC

//#include <stdlib.h>
//#include <crtdbg.h>
#include <windows.h>
//#include <tchar.h>

class MmLeak
{
    static BOOL Check(PTCHAR logfile);
};

#endif 


#include "mm.h"

BOOL MmLeak::Check(PTCHAR logfile)
{
#if defined(_DEBUG) && defined (_MEMORY_LEAK_CHECK_)
    HANDLE hpf;
    if (_tcslen(log) > MAX_PATH) {
        return FALSE;
    }
    hpf = CreateFile(logfile, GENERIC_WRITE,
        FILE_SHARE_WRITE, NULL, CREATE_ALWAYS, FILE_ATTRIBUTE_NORMAL, NULL);

    _CrtSetReportMode(_CRT_WARN, _CRTDBG_MODE_FILE);
    _CrtSetReportFile(_CRT_WARN, hpf);
    _CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
#endif

    return TRUE;
}
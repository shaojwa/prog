
#include <time.h>
#include <windows.h>
#include <stdio.h>

void print_time()
{
    FILETIME ftime;
    SYSTEMTIME stime;
    ftime.dwHighDateTime = 0x2c040c11;
    ftime.dwLowDateTime = 0x19360000;
    BOOL success = FileTimeToSystemTime(&ftime, &stime);
    if (success)
    {
        printf("%d-%d-%d %d:%d:%d\n", stime.wYear, stime.wMonth, stime.wDay,
            stime.wHour, stime.wMinute, stime.wSecond);
    }
}
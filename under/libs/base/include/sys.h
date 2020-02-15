

#ifndef SYS_H
#define SYS_H

#include <Windows.h>
#include <tchar.h>

#define DllExport __declspec( dllexport )

class DllExport Sys
{
public:
    Sys(){}
    ~Sys(){}
    static int getNumberOfProcessors(void);
    static int getUsbVol(char* vols, int size);
};

#endif
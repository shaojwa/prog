

#ifndef SH_H
#define SH_H

#include <windows.h>
#include <tchar.h>

class Shell {
public:
    bool copyFile(LPCTSTR from, LPCTSTR to);
};
#endif 
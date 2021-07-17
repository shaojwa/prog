

#include "sys.h"
#include <stdio.h>

int Sys::getNumberOfProcessors() 
{
    SYSTEM_INFO si;
    GetNativeSystemInfo(&si);
    return si.dwNumberOfProcessors;
}


int Sys::getUsbVol(char* vols, int size) 
{
    TCHAR targetPath[MAX_PATH];
    bool isUsb[32] = {0};
    DWORD mask = 0x01;
    TCHAR volPath[] = _T("\\\\.\\X:");
    DWORD numVols = 0;
    HANDLE hVol = INVALID_HANDLE_VALUE;
    VOLUME_DISK_EXTENTS diskExtents;
    DWORD dwSize;
    DWORD errcode;
    DWORD disNum;

    FILE *pipe = NULL;
    char line[MAX_PATH];
    int index;
    char type[16];

    pipe = _popen("wmic diskdrive get index, interfaceType", "rt");
    if (NULL == pipe) {
        return -1;
    }

    for(int i = 0; i < 32; i++) {
        isUsb[i] = false;
    }

    int ret = 0;
    while (!feof(pipe)) {
        if ((fgets(line, MAX_PATH, pipe) != NULL)) {
            ret = sscanf(line, "%d %s\n", &index, &type);
            if (0!= ret && EOF != ret && (0 == stricmp(type, "USB"))) {
                isUsb[index] = true;
            }
        }
    }

    int count = 0;
    numVols = GetLogicalDrives();
    for (int i = 0; i < 26;i ++) {
        mask = (0x01 << i);
        if ((numVols & mask) == 0) {
            continue;
        }

        volPath[_tcslen(_T("\\\\.\\"))] = _T('A') + i;
        hVol = CreateFile((LPCTSTR)volPath, 0, 0,
            NULL, OPEN_EXISTING, NULL, NULL);
        if (INVALID_HANDLE_VALUE == hVol) { 
            errcode = GetLastError();
            continue;
        }
        if (!DeviceIoControl(
            (HANDLE)hVol,
            IOCTL_VOLUME_GET_VOLUME_DISK_EXTENTS,
            NULL,
            0,
            (LPVOID) &diskExtents,
            (DWORD) sizeof(diskExtents),
            (LPDWORD) &dwSize,
            NULL)) {
                errcode = GetLastError();
                continue;
        }
        disNum = diskExtents.Extents[0].DiskNumber;
        if (isUsb[disNum] && count < size) {
            vols[count] = 'a' + i;
            count++;
        }
    }
    return count;
}

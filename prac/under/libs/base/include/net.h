

#ifndef NET_H
#define NET_H

#include <ws2tcpip.h>
#include <windows.h>
#include <tchar.h>

#define DllExport __declspec( dllexport )

class DllExport Net {
public:
    bool addRouteItem(LPCTSTR adapterName, unsigned destIp, unsigned mask);
    bool deleteRouteItem(unsigned destIp, unsigned mask);
    unsigned getIpByAdapter(char* adapterName);
    unsigned getMaskByAdapter(char* adapterName);
    unsigned getMaskByIp(char * ip);
    int getIpByHostname(char * hostname, char* ip);
    int hostnameToIp(char * hostname, char* ip);
};


#endif

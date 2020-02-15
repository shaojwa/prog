

#include "net.h"

#include <iphlpapi.h>


#pragma comment(lib, "iphlpapi.lib")
#pragma comment(lib, "Ws2_32.lib")


bool Net::addRouteItem(LPCTSTR adapterName, unsigned destIp, unsigned mask)
{
    PMIB_IPFORWARDROW pRow = NULL;
    DWORD status = 0;
    bool result = FALSE;
    DWORD ip = 0;
    DWORD if_index = 0;

    pRow = (PMIB_IPFORWARDROW) malloc(sizeof(MIB_IPFORWARDROW));
    if (!pRow) {
        return false;
    }
    pRow->dwForwardDest = htonl(0x01000001);
    pRow->dwForwardMask = htonl(0xffffffff);
    pRow->dwForwardPolicy = 0;
    pRow->dwForwardNextHop = htonl(ip);
    pRow->dwForwardIfIndex = if_index;
    pRow->dwForwardType = MIB_IPROUTE_TYPE_DIRECT;
    pRow->dwForwardProto = MIB_IPPROTO_NETMGMT;
    pRow->dwForwardAge = 0;
    pRow->dwForwardNextHopAS = 0;
    pRow->dwForwardMetric1 = -1;
    pRow->dwForwardMetric2 = -1;
    pRow->dwForwardMetric3 = -1;
    pRow->dwForwardMetric4 = -1;
    pRow->dwForwardMetric5 = -1;

    result = false;
    status = CreateIpForwardEntry(pRow);
    if (status == NO_ERROR) {
        result = true;
    }
    return result;
}


bool Net::deleteRouteItem(unsigned destIp, unsigned mask)
{
    bool result = false;
    PMIB_IPFORWARDTABLE pIpForwardTable = NULL;
    DWORD status = 0;
    DWORD size = 0;
    DWORD i = 0;
    BOOL order = FALSE;

    status = GetIpForwardTable(pIpForwardTable, &size, order);
    if (status == ERROR_INSUFFICIENT_BUFFER)
    {
        pIpForwardTable = (PMIB_IPFORWARDTABLE) malloc(size);
        if (NULL == pIpForwardTable) {
            return false;
        }
        status = GetIpForwardTable(pIpForwardTable, &size, order);
    }

    if (status != ERROR_SUCCESS) {
        free(pIpForwardTable);
        return false;
    }

    for (i = 0; i < pIpForwardTable->dwNumEntries; i++)
    {
        if (pIpForwardTable->table[i].dwForwardDest == 0x01000001)
        {
            status = DeleteIpForwardEntry(&(pIpForwardTable->table[i]));
            if (status == ERROR_SUCCESS) {
                result = false;
            }
            break;
        }
    }
    free(pIpForwardTable);
    return result;
}


/************************************************************************
功能：通过网卡名获取ip和mask
************************************************************************/
unsigned getIpByAdapter(char* adapterName)
{
    PIP_ADAPTER_INFO pAdapterInfo = NULL;
    ULONG outBufLen = sizeof (IP_ADAPTER_INFO);
    DWORD retVal = 0;
    unsigned ip = 0;

    pAdapterInfo = (IP_ADAPTER_INFO *) malloc (sizeof (IP_ADAPTER_INFO));
    if (NULL == pAdapterInfo) {
        return -1;
    }
    
    retVal = GetAdaptersInfo(pAdapterInfo, &outBufLen);
    if (ERROR_BUFFER_OVERFLOW == retVal) {
        free(pAdapterInfo);
        pAdapterInfo = (IP_ADAPTER_INFO *)malloc(outBufLen); 
        if (NULL == pAdapterInfo) {
            return 0;
        }
        retVal = GetAdaptersInfo(pAdapterInfo, &outBufLen);
    }

    if (retVal != NO_ERROR) {
         free(pAdapterInfo);
         return 0;
    }

    IP_ADAPTER_INFO *pAdapter = pAdapterInfo;
    BOOL bFound = FALSE;
    while(pAdapter) {
        if (0 == strcmp(pAdapter->AdapterName, adapterName)) {
            IP_ADDR_STRING ipAddrStrList = pAdapter->IpAddressList;
            while(true) {
                if (0 != strcmp(ipAddrStrList.IpAddress.String, "0.0.0.0")) {
                    ip = ntohl(inet_addr(ipAddrStrList.IpAddress.String));
                    break;
                }
                ipAddrStrList = *ipAddrStrList.Next;
            }
            break;
        }
        pAdapter = pAdapter->Next;
    }

    if (pAdapterInfo)
    {
        free(pAdapterInfo);
    }
    return ip;
}

unsigned Net::getMaskByAdapter(char* adapter_name)
{
    PIP_ADAPTER_INFO pAdapterInfo = NULL;
    ULONG outBufLen = sizeof (IP_ADAPTER_INFO);
    DWORD retVal = 0;
    unsigned mask = 0;

    pAdapterInfo = (IP_ADAPTER_INFO *) malloc (sizeof (IP_ADAPTER_INFO));
    if (NULL == pAdapterInfo) {
        return 0;
    }

    retVal = GetAdaptersInfo(pAdapterInfo, &outBufLen);
    if (ERROR_BUFFER_OVERFLOW == retVal) {
        free(pAdapterInfo);
        pAdapterInfo = (IP_ADAPTER_INFO *)malloc(outBufLen); 
        if (NULL == pAdapterInfo) {
            return 0;
        }
        retVal = GetAdaptersInfo(pAdapterInfo, &outBufLen);
    }

    if (retVal != NO_ERROR) {
        free(pAdapterInfo);
        return 0;
    }
    IP_ADAPTER_INFO *pAdapter = pAdapterInfo;
    BOOL bFound = FALSE;
    while(pAdapter) {
        if (0 == strcmp(pAdapter->AdapterName, adapter_name)) {
            IP_ADDR_STRING ipAddrStrList = pAdapter->IpAddressList;
            while(true) {
                if (0 != strcmp(ipAddrStrList.IpAddress.String, "0.0.0.0")) {
                    mask = ntohl(inet_addr(ipAddrStrList.IpMask.String));
                    break;
                }
                ipAddrStrList = *ipAddrStrList.Next;
            }
            break;
        }
        pAdapter = pAdapter->Next;
    }

    if (pAdapterInfo) {
        free(pAdapterInfo);
    }
    return mask;
}


/************************************************************************
函数名称  :get_mask_by_ip
功能描述  :获取IP地址对应的掩码
************************************************************************/
unsigned Net::getMaskByIp(char* ip)
{
    BOOL ret = FALSE;
    IP_ADAPTER_INFO * pAdapterInfo = (IP_ADAPTER_INFO *)malloc( sizeof(IP_ADAPTER_INFO));
    unsigned mask = 0;
    if (!pAdapterInfo) {
        return 0;
    }

    ULONG ulOutBufLen = sizeof(IP_ADAPTER_INFO);
    if (ERROR_BUFFER_OVERFLOW == GetAdaptersInfo(pAdapterInfo, &ulOutBufLen)) {
        free(pAdapterInfo);
        pAdapterInfo = (IP_ADAPTER_INFO *)malloc(ulOutBufLen); 
        if (NULL == pAdapterInfo) {
            return 0;
        }
    }

    if (GetAdaptersInfo(pAdapterInfo, &ulOutBufLen) != NO_ERROR) {
        free(pAdapterInfo);
        return 0;;
    }

    IP_ADAPTER_INFO *pAdapter = pAdapterInfo;
    BOOL bFound = FALSE;
    while(pAdapter) {
        IP_ADDR_STRING ipAddrStrList = pAdapter->IpAddressList;
        while(true) {
            if (!strcmp(ipAddrStrList.IpAddress.String, ip)) {
                bFound = TRUE;
                mask = ntohl(inet_addr(ipAddrStrList.IpMask.String));
                break;
            }
            if (ipAddrStrList.Next == NULL) {
                break;
            }
            ipAddrStrList = *ipAddrStrList.Next;
        }

        if (bFound)
        {
            break;
        }
        pAdapter = pAdapter->Next;
    }
    if (pAdapterInfo) {
        free(pAdapterInfo);
    }
    return mask;
}


int Net::getIpByHostname(char * hostname, char* ip) {
    DWORD retval = 0;
    struct hostent *host = gethostbyname(hostname);
    if (host == NULL) {
        return 1;
    }
    in_addr** addr_list = (struct in_addr**) host->h_addr_list;
    // return the first one
    for(int i = 0; addr_list[i] != NULL; i++) {
        strcpy(ip, inet_ntoa(*addr_list[i]));
        return 0;
    }
    return 1;
}

int Net::hostnameToIp(char * hostname, char* ip) {
    int sockfd;
    struct addrinfo hints, *servinfo, *p;
    struct sockaddr_in *h;
    int rv;
    
    memset(&hints, 0, sizeof hints);
    hints.ai_family = AF_UNSPEC;
    hints.ai_socktype = SOCK_STREAM;

    if ((rv = getaddrinfo(hostname, "http", &hints, &servinfo)) != 0) {
        return 1;
    }

    for (p = servinfo; p != NULL; p = p->ai_next) {
        h = (struct sockaddr_in *) p->ai_addr;
        strcpy(ip, inet_ntoa(h->sin_addr));
    }
    freeaddrinfo(servinfo);
    return 0;
}
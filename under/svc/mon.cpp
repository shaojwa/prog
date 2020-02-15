

#include "log.h"
#include "mon.h"

bool Mon::init(void) {
    return true;
}



//
//bool NetMon::m_inited = false;
//NetMon *NetMon::m_instance = NULL;
//bool NetMon::m_network_ok = true;
//char NetMon::m_adapter_name[MAX_ADAPTER_NAME_LENGTH + 4] = {0};
//
//bool NetMon::StartMonThread(void)
//{
//    DWORD monNetTid = 0;
//    HANDLE monNetThread = NULL;
//    monNetThread = CreateThread(NULL, 0, MonNetwork, NULL, 0, &monNetTid);
//    if (!monNetThread)
//    {
//        LOG("error(%d):create mon_network thread failed.", GetLastError());
//        return false;
//    }
//    return true;
//}
//
//
//DWORD CALLBACK NetMon::MonNetwork(LPVOID arg)
//{
//    OVERLAPPED overlap;
//    DWORD ret;
//    HANDLE hand = NULL;
//    overlap.hEvent = WSACreateEvent();
//    bool need_reconnect = false;
//
//    while(true)
//    {
//        ret = NotifyAddrChange(&hand, &overlap);
//        if (ERROR_IO_PENDING != ret)
//        {
//            LOG("error: call NotifyAddrChange() fail.");
//        }
//        ret = WaitForSingleObject(overlap.hEvent, INFINITE);
//        if (WAIT_OBJECT_0 == ret)
//        {
//            LOG("**** get addr-change notice.");
//            if (Check(need_reconnect) && need_reconnect)
//            {
//                LOG("try to login again...");
//                need_reconnect = false;
//            }
//        }
//    }
//    return 0;
//}
//
//
//bool NetMon::Check(bool& need_reconnect)
//{
//    PIP_ADAPTER_INFO pAdapterInfo = NULL;
//    PIP_ADAPTER_INFO pAdapter = NULL;
//    PIP_ADDR_STRING pIpAddr;
//    DWORD dwOutBufLen = 0;
//
//    pAdapterInfo = (IP_ADAPTER_INFO *) malloc( sizeof(IP_ADAPTER_INFO) ); 
//    if (NULL == pAdapterInfo)
//    {
//        LOG("error: malloc failed");
//        need_reconnect = false;
//        return false;
//    }
//    dwOutBufLen = sizeof(IP_ADAPTER_INFO);
//
//    if (ERROR_BUFFER_OVERFLOW == GetAdaptersInfo(pAdapterInfo,&dwOutBufLen))
//    {
//        free(pAdapterInfo);
//        pAdapterInfo = (IP_ADAPTER_INFO *)malloc(dwOutBufLen);
//        if (pAdapterInfo == NULL)
//        {
//            LOG("error: malloc failed");
//            need_reconnect = false;
//            return false;
//        }
//    }
//    bool is_conn_ok = false;
//    if (ERROR_SUCCESS == GetAdaptersInfo( pAdapterInfo, &dwOutBufLen)) 
//    {
//        pAdapter = pAdapterInfo;
//        while (pAdapter)
//        {
//            if (0 == strcmp(pAdapter->AdapterName, m_adapter_name))
//            {
//                pIpAddr = &(pAdapter->IpAddressList);
//                while (pIpAddr)
//                {
//                    if (0 != strcmp(pIpAddr->IpAddress.String, "0.0.0.0") &&
//                        0 != strcmp(pIpAddr->IpMask.String, "0.0.0.0"))
//                    {
//                        is_conn_ok = true;
//                        break;
//                    }
//                    pIpAddr = pIpAddr->Next;
//                }
//                break;
//            }
//            pAdapter = pAdapter->Next;
//        }
//    }
//    if (!is_conn_ok)
//    {
//        LOG("network error.");
//        m_network_ok = false;
//    }
//    if (!m_network_ok && is_conn_ok)
//    {
//        LOG("need_reconnect.");
//        need_reconnect = true;
//        m_network_ok = true;
//    }
//    free(pAdapterInfo);
//    return true;
//}



#include "../common/stdafx.h"
#include "../common/logger.h"
#include "../common/net.h"

#include "config.h"


int fun_c(int x)
{
    int ret = 0;
    ret = x;
    return ret;
}

int fun_b(int x)
{
    int ret = 0;
    ret = fun_c(x);
    return ret;
}

int fun_a(int x)
{
    int ret = 0;
    ret = x + fun_b(x);
    return ret;
}

int test_invoke(int a, int b, int c, int d)
{
    int ret = 0;
    ret = fun_a(a + b + c + d);
    return ret;
}

void test(void)
{
    DWORD ip= 0;
    DWORD mask = 0;
    BOOL ret = FALSE;
    Logger::Instance().Open(SRV_CONFIG_LOGFILE);

    CHAR adapter_name[] = "{D079A262-111D-407D-A12C-305E72E1454D}";
    ret = get_ipmask_by_adapter(adapter_name, &ip, &mask);
    if (!ret)
    {
        LOG(LL_INFO, "error: get_ipmask_by_adapter() fail");
    }
    else
    {
        LOG(LL_INFO,"ip = 0x%08x, mask = 0x%08x", ip, mask);
    }

    in_addr ipaddr;
    ipaddr.s_addr = htonl(ip);
    ret = get_mask_by_ip(inet_ntoa(ipaddr), &mask);
    if (!ret)
    {
        LOG(LL_INFO,"error: get_mask_by_ip() fail");
    }
    else
    {
        LOG(LL_INFO,"ip = 0x%08x, mask = 0x%08x", ip, mask);
    }
}

#include "../common/logger.h"
#include "../common/cmdutil.h"

#include <tchar.h>

const LPCTSTR pipename = _T("\\\\.\\pipe\\namedpipe_cmdutil");
const LPCTSTR logname = _T("namedpipe.log");

//int _tmain(int argc, TCHAR *argv[])
//{
//    Logger::Instance().Open(logname);
//    NEXT_STEP next = CmdUtil::ParseCmd(pipename);
//    if (NS_EXIT == next)
//    {
//        Logger::Instance().Close();
//        exit(0);
//    }
//    if (!CmdUtil::StartListenThread(pipename))
//    {
//        LOG("start listen-thread fail");
//        Logger::Instance().Close();
//    }
//    int cmd = 0;
//    while(true)
//    {
//        printf("please input a number: ");
//        scanf("%d", &cmd);
//        if (0 == cmd)break;
//    }
//    Logger::Instance().Close();
//    return 0;
//}
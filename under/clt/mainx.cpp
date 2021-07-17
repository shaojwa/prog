
#include "net.h"
#include "sys.h"
#include "log.h"
#include "cl.h"


#include <stdio.h>

bool init() {
    if (!Log::getInst().open(_T(".\\logs.txt"))) {
        return false;
    }
    return true;
}

int main()
{
    int ret = 0;
    int size = 4;
    int num = 0;
    char* pVols = new char[size];
    init();
    num = Sys::getNumberOfProcessors();
    ret = Sys::getUsbVol(pVols, size);
    Log::getInst().tprint(LOG::LEVEL_DEBUG, _T("num = %d"), num);
    Log::getInst().tprint(LOG::LEVEL_DEBUG, _T("usb = %d"), ret);

    //Cl::getInst().parseArgs();
    //Cl::getInst().createPipe(NULL);
    //Cl::getInst().startListen();

    Net* nt = new Net();

    char ip[32] = {0};
    nt->hostnameToIp("gmail.com", ip);
    Log::getInst().print(LOG::LEVEL_DEBUG, "hostnameToIp returns %s\n", ip);

    nt->getIpByHostname("gmail.com", ip);
    Log::getInst().print(LOG::LEVEL_DEBUG, "getipbyhostname returns %s\n", ip);



    //else if (1 == nArgs)
    //{
    //    LOG(LL_INFO, "nArgs = %d", nArgs);
    //    /*如果不带参数则判断是否有实例已经在运行*/
    //}
    //else if (2 == nArgs && 0 == lstrcmpi(szArglist[1], _T("-exit")))
    //{
    //    HANDLE pipe = OpenPipe(pipename);
    //    if (pipe != INVALID_HANDLE_VALUE)
    //    {
    //        SendCmdRequest(szArglist[1]);
    //        Logger::Instance().Close();
    //        ClosePipe();
    //    }
    //    result = NS_EXIT;
    //}
    //else
    //{
    //    result = NS_EXIT;
    //}

    return 0;
}





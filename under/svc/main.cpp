
#include "svc.h"
#include "cl.h"
#include "config.h"

#include "log.h"

#include <assert.h>
#include <string.h>
#include <stdio.h>
#include <signal.h>
#include <tchar.h>
#include <math.h>
#include <string>
#include <iostream>
using namespace std;


int _tmain(int argc, TCHAR *argv[])
{
    if(!Log::getInst().open(SVC_CONFIG_LOGFILE)) {
        exit(-1);
    }
    logline(LOG::LEVEL_INFO, "main tid = %d", GetCurrentThreadId());

    if (lstrcmpi(argv[1], _T("install")) == 0) {
        if (!svcInstall()) {
            logline(LOG::LEVEL_ERROR, "install service failed.");
            exit(-1);
        }
    }

    Cl *pcl = new Cl;
    if (pcl == NULL) {
        logline(LOG::LEVEL_ERROR, "create cl failed.");
        exit(-1);
    }
#ifdef _DEBUG
    pcl->attachDbgCon();
#endif

    if (!svcStartup()) {
        logline(LOG::LEVEL_ERROR, "start service failed.");
        exit(-1);
    }
    return 0;
}



#ifndef CONFIG_H
#define CONFIG_H


//
// client settings
//
#define CLT_EVENTNAME_WAIT2WORK     _T("CLT_EVNETNAME_WAIT2WORK")
#define CLT_MAINFRAME_TITLE         _T("UNDER")
#define CLT_DIALOG_TITLE            _T("UNDER")
#define CLT_CONNECT_INTERVAL        5000
//
// service settings
//
#define SVC_CONFIG_LOGFILE          _T("underd.log")
#define SVC_CONFIG_SERVICE_NAME     _T("under")
#define SVC_CONFIG_DISPLAY_NAME     _T("under")
#define SVC_CONFIG_BINARY_NAME      _T("underd.exe")
#define SVC_CONFIG_LISTEN_PORT      11102



namespace PROTO {
    enum module {
        MODULE_MONITOR = 0,
        MODULE_POLICY = 1,
        MODULE_ANALYSE  = 2,
        MODULE_HARDWARE = 3,
        MODULE_SOFTWARE = 4
    };

    enum command {
        CMD_HOST_DISCOVER = 0,
        CMD_PORT_SCAN = 1,
        CMD_VERSION_DETECTION = 2,
        CMD_SERVICE_DETECTION = 3,
        CMD_OS_DETECTION = 4
    };
}


#endif

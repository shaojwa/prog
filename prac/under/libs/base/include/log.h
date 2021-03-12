

#ifndef LOG_H
#define LOG_H

#include <windows.h>
#include <tchar.h>
#include <stdio.h>
#include <string.h>
#include <sstream>

using namespace std;

#define DllExport __declspec( dllexport )

#ifdef _UNICODE
#define tstring wstring
#define tstringstream wstringstream
#else
#define tstring string
#define tstringstream stringstream
#endif


#ifdef _DEBUG
#define logline(level, fmt, ...) Log::getInst().print(level, "%s():%d:"fmt"\n", __FUNCTION__, __LINE__, ##__VA_ARGS__)
#define logtline(level, fmt, ...) Log::getInst().tprint(level, _T("%s():%d:") fmt _T("\n"), _T(__FUNCTION__), __LINE__, ##__VA_ARGS__)
#else
#define logprint(fmt, ...)
#define logtprint(fmt, ...)
#endif


namespace LOG {
    enum mode { MODE_STDOUT = 0, MODE_FILE};
    enum level { LEVEL_FATAL = 0, LEVEL_ERROR, LEVEL_WARN, LEVEL_INFO, LEVEL_DEBUG };
}

class DllExport Log
{
public:
    static Log& getInst(void);
    bool clear(void);

    bool open(LPCTSTR logname);
    void close(void);
    void print(unsigned int level, LPCSTR fmt, ...);
    void tprint(int level, LPCTSTR fmt, ...);

    void setLogMode(int mode);
    void setLogLevel(int level);

private:
    Log(void);
    ~Log(void);
    int m_loglevel;
    int m_logmode; /* log to stdin or file */
    static Log *m_instance; 
    static bool m_inited;
    FILE *m_log_fp;
    CRITICAL_SECTION m_lock;
    tstring m_exe_dir;
    tstringstream m_fullpath;
};

#endif

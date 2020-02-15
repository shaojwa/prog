


#include "log.h"
#include <time.h>

bool Log::m_inited = false;
Log* Log::m_instance = NULL;
static char* gsLogLabels[] =
{
    "FATAL",
    "ERROR",
    "WARN",
    "INFO",
    "DEBUG"
};

Log::Log(void):m_loglevel(LOG::LEVEL_DEBUG), m_logmode(LOG::MODE_STDOUT),m_log_fp(NULL)
{
    TCHAR dir[MAX_PATH];
    DWORD nCount = 0;
    nCount = GetModuleFileName(NULL, dir, MAX_PATH);
    dir[MAX_PATH - 1] = 0;
    m_exe_dir = dir;
    m_exe_dir = m_exe_dir.substr(0, m_exe_dir.rfind('\\'));
    m_exe_dir += _T('\\');

    setlocale(LC_ALL, "chs");
    ::InitializeCriticalSection(&m_lock);
}

Log::~Log(void)
{
    close();
    ::DeleteCriticalSection(&m_lock);
}


Log& Log::getInst(void)
{
    if (!m_inited)
    {
        m_instance = new Log();
        m_inited = true;
    }
    return *m_instance;
}


bool Log::open(LPCTSTR logname)
{
    bool ret = true;
    m_fullpath << m_exe_dir << logname;
    ::EnterCriticalSection(&m_lock);
    if(!m_log_fp) {
        m_log_fp = _tfopen(m_fullpath.str().c_str(), _T("a+"));
        if (NULL == m_log_fp) {
            ret = false;
        }
    }
    ::LeaveCriticalSection(&m_lock);
    if (ret) {
        setLogMode(LOG::MODE_FILE);
    }
    return ret;
}


void Log::close(void)
{
    ::EnterCriticalSection(&m_lock);
    if(m_log_fp)
    {
        fflush(m_log_fp);
        fclose(m_log_fp);
        m_log_fp = NULL;
    }
    ::LeaveCriticalSection(&m_lock);
}


void Log::tprint(int level, LPCTSTR fmt, ...)
{
    if (level > sizeof(gsLogLabels)/sizeof(char *) - 1)
    {
        return;
    }

    if (level > m_loglevel)
    {
        return;
    }
    va_list list; 
    va_start(list, fmt);
    TCHAR szTime[MAX_PATH];
    time_t now = time(NULL);
    _tcsftime(szTime, MAX_PATH, _T("%c"), localtime(&now));

    ::EnterCriticalSection(&m_lock);
    if(m_log_fp) {
        _ftprintf(m_log_fp, _T("[%s]"), szTime); 
        _vftprintf(m_log_fp, fmt, list);
        fflush(m_log_fp);
    }
    ::LeaveCriticalSection(&m_lock);
    va_end(list);
    return;
}

void Log::print(unsigned int level, LPCSTR fmt, ...)
{
    if (level > sizeof(gsLogLabels)/sizeof(char *) - 1)
    {
        return;
    }
    if (level > m_loglevel)
    {
        return;
    }

    va_list list; 
    va_start(list, fmt);
    char szTime[MAX_PATH];
    time_t now = time(NULL);
    strftime(szTime, MAX_PATH, "%c", localtime(&now));

    ::EnterCriticalSection(&m_lock);
    if (LOG::MODE_STDOUT == m_logmode)
    {
        printf("[%s]:", gsLogLabels[level]);
        vprintf(fmt, list);
        goto end;
    }

    if(m_log_fp)
    {
        fprintf(m_log_fp, "[%s]", szTime); 
        vfprintf(m_log_fp, fmt, list);
        fflush(m_log_fp);
    }

end:
    ::LeaveCriticalSection(&m_lock);
    va_end(list);
}


void Log::setLogLevel(int level)
{
    ::EnterCriticalSection(&m_lock);
    m_loglevel = level;
    ::LeaveCriticalSection(&m_lock);
}

void Log::setLogMode(int mode)
{
    ::EnterCriticalSection(&m_lock);
    m_logmode = mode;
    ::LeaveCriticalSection(&m_lock);
}

bool Log::clear(void)
{
    bool ret = true;
    ::EnterCriticalSection(&m_lock);
    if (m_log_fp != NULL)
    {
        m_log_fp = _tfreopen(m_fullpath.str().c_str(), _T("w"), m_log_fp);
        if (NULL == m_log_fp)
        {
            ret = false;
        }
    }
    ::LeaveCriticalSection(&m_lock);
    return ret;
}

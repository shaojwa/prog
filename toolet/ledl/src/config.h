

#ifndef CONFIG_H
#define CONFIG_H

#include <windows.h>
#include <tchar.h>


enum EExtratType {
    EXTRACT_TYPE_AUTO = 0,
    EXTRACT_TYPE_CUSTOM
};


class CConfig {
public :
    CConfig();
    ~CConfig();

    LPCTSTR getPattern();
    int setPattern(LPCTSTR patt);

    LPCTSTR getSrc();
    int setSrc(LPCTSTR src);

    LPCTSTR getDst();
    int setDst(LPCTSTR dest);

    EExtratType getExtractType();
    void setExtractType(EExtratType type);

    int getProgress();
    void setProgress(int);

private:
    TCHAR m_pattern[MAX_PATH];
    TCHAR m_szSrc[MAX_PATH];
    TCHAR m_szDst[MAX_PATH];
    int m_nProgress;
    EExtratType m_extractType;
};

enum EUserMessage {
    USER_MSG_TASK_STATE = WM_USER + 1000,
};


enum ETaskState {
    TASK_STATE_INIT = 0,
    TASK_STATE_PENDING,
    TASK_STATE_INPROCESS,
    TASK_STATE_FINISHED
};

enum ETaskType {
    TASK_TYPE_NONE = 0,
    TASK_TYPE_SYS_PROCESSES,
    TASK_TYPE_SYS_OPERATION,
    TASK_TYPE_SVC_WEB,
    TASK_TYPE_SVC_SMB,
    TASK_TYPE_SVC_FTP,
    TASK_TYPE_SVC_SSH,
    TASK_TYPE_SVC_DATABASE
};


#endif
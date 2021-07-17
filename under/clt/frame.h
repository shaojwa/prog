
#ifndef MAINFRAME_H
#define MAINFRAME_H

#include "config.h"
#include "UIlib.h"

using namespace DuiLib;

class Frame: public CWindowWnd, public INotifyUI {
public:
    Frame(){}
    ~Frame(){}
    LPCTSTR GetWindowClassName() const;
    UINT GetClassStyle() const; 
    void OnFinalMessage(HWND );
    void Notify(TNotifyUI & msg);
    LRESULT HandleMessage (UINT uMsg, WPARAM wParam, LPARAM lParam);

public:
    void attachEvent(HANDLE);

private:
    CPaintManagerUI m_pm;
    static int m_gEvtNum;
    CHorizontalLayoutUI *m_phlOptions;
    CButtonUI *m_pbtnOptions;
    CButtonUI *m_pbtnAbout;
    CButtonUI *m_pbtnScan;
    CButtonUI *m_pbtnCancel;
    CHorizontalLayoutUI *m_phlProgress;
    CProgressUI * m_pprgScan;
    CListUI* m_plstLogs;

    HANDLE m_event2find;
};

#endif
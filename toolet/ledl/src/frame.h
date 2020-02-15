

#include "config.h"
#include "UIlib.h"
#include "worker.h"

using namespace DuiLib;

class Frame: public CWindowWnd, public INotifyUI {
public:
    Frame(){};
    LPCTSTR GetWindowClassName() const;
    UINT GetClassStyle() const; 
    void OnFinalMessage(HWND );
    void Notify(TNotifyUI & msg);
    LRESULT HandleMessage (UINT uMsg, WPARAM wParam, LPARAM lParam);

public:
    void attachEvent(HANDLE hExtractEvent);
    int attachConfig(CConfig *);
    bool browseFile(CEditUI *pedit);

private:
    void UpdateTaskStateUI(const ETaskType type, const ETaskState state);

    CPaintManagerUI m_pm;
    static int m_gEvtNum;

    CHorizontalLayoutUI *m_phlTitleBar;
    CLabelUI *m_plblProductName;
    CLabelUI *m_plblToolName;
    CButtonUI *m_pbtnMin;
    CButtonUI *m_pbtnMax;
    CButtonUI *m_pbtnClose;

    //控制面板相关
    CHorizontalLayoutUI *m_phlControlPanel;
    CButtonUI *m_pbtnStop;
    CButtonUI *m_pbtnBack;
    CLabelUI *m_plblExtractState;

    //主面板相关
    CTabLayoutUI * m_ptlMainPanel;
    CHorizontalLayoutUI * m_phlOptions;
    CTabLayoutUI * m_ptlExtractType;
    CButtonUI *m_pbtnExtractAuto;
    CButtonUI *m_pbtnAdvance;
    CButtonUI *m_pbtnCloseAdvance;
    CEditUI *m_pedtPattern;
    CEditUI *m_pedtSrc;
    CEditUI *m_pedtDst;
    CButtonUI *m_pbtnExtractCust;
    CButtonUI *m_pbtnSrcBrowse;
    CButtonUI *m_pbtnDstBrowse;

    CHorizontalLayoutUI * m_phlProcess;
    CLabelUI *m_plblProcessState;

    CHorizontalLayoutUI * m_phlOper;
    CLabelUI *m_plblOperState;

    CHorizontalLayoutUI * m_phlWeb;
    CLabelUI *m_plblWebState;

    CHorizontalLayoutUI * m_phlSsh;
    CLabelUI *m_plblSshState;

    CHorizontalLayoutUI * m_phlFtp;
    CLabelUI *m_plblFtpState;

    CHorizontalLayoutUI * m_phlSmb;
    CLabelUI *m_plblSmbState;

    CHorizontalLayoutUI * m_phlDatabase;
    CLabelUI *m_plblDatabaseState;

    HANDLE m_hExtractEvent;
    CConfig *m_pConfig;
    CWorker *m_pWorker;
};
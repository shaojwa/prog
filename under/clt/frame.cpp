

#include "frame.h"
#include "log.h"

#include "Shlwapi.h"

int Frame::m_gEvtNum = 0;

#define STRING_EMPTY    _T("")
#define PROMPT_PATTERN_EMPTY        _T("提示：匹配模式为空，请输入合法正则表达式。")
#define PROMPT_PATTERN_INVALID      _T("提示：匹配模式有误，请输入合法正则表达式。")
#define PROMPT_SRC_INVALID          _T("提示：搜索路径不存在，请确认路径是否正确。")
#define PROMPT_DEST_INVALID         _T("提示：备份路径不存在，请确认路径是否正确。")

void Frame::OnFinalMessage(HWND ) {
    delete this;
}

LPCTSTR Frame::GetWindowClassName() const {
    return _T("UIMainFrame");
}

UINT Frame::GetClassStyle() const {
    return UI_CLASSSTYLE_FRAME | CS_DBLCLKS;
}

void Frame::Notify(TNotifyUI & msg) {
    if (msg.sType == DUI_MSGTYPE_CLICK) {
        if (msg.pSender->GetName() == _T("closebtn")) {
            Close();
        } else if (msg.pSender->GetName() == _T("btnOptions")) {
        } else if (msg.pSender->GetName() == _T("btnStart")) {
            m_phlProgress->SetVisible(true);
            SetEvent(m_event2find);
        } else if (msg.pSender->GetName() == _T("btnCancel")) {
        }
    } else if (msg.sType == DUI_MSGTYPE_SETFOCUS) {
        if (msg.pSender->GetName() == _T("edtPattern")) {
            msg.pSender->SetAttribute(_T("textcolor"), _T("#FF000000"));
        } else if (msg.pSender->GetName() == _T("edtSrc")) {
            msg.pSender->SetAttribute(_T("textcolor"), _T("#FF000000"));
        } else if (msg.pSender->GetName() == _T("edtDest")) {
            msg.pSender->SetAttribute(_T("textcolor"), _T("#FF000000"));
        }
    }
}


LRESULT Frame::HandleMessage (UINT uMsg, WPARAM wParam, LPARAM lParam) {

    if (uMsg == WM_CREATE ){
        logline(LOG::LEVEL_INFO, "MSG#%d: WM_CREATE", m_gEvtNum++);
        m_pm.Init(m_hWnd);
        CDialogBuilder builder;
        CControlUI * pRoot = builder.Create(_T("res\\frame.xml"), NULL, NULL, &m_pm);
        ASSERT(pRoot && "Failed to parse xml");
        m_pm.AttachDialog(pRoot);
        m_pm.AddNotifier(this);

        m_phlOptions = static_cast<CHorizontalLayoutUI *>(m_pm.FindControl(_T("hlOptions")));
        if (m_phlOptions == NULL) {
            logline(LOG::LEVEL_FATAL, "m_phlTool == NULL");
            exit(1);
        }
        m_pbtnOptions = static_cast<CButtonUI *>(m_pm.FindControl(_T("btnOptions")));
        if (m_pbtnOptions == NULL) {
            logline(LOG::LEVEL_FATAL, "m_pbtnOptions == NULL");
            exit(1);
        }
        m_pbtnAbout = static_cast<CButtonUI *>(m_pm.FindControl(_T("btnAbout")));
        if (m_pbtnAbout == NULL) {
            logline(LOG::LEVEL_FATAL, "m_pbtnAbout == NULL");
            exit(1);
        }
        m_pbtnScan = static_cast<CButtonUI *>(m_pm.FindControl(_T("btnScan")));
        if (m_pbtnScan == NULL) {
            logline(LOG::LEVEL_FATAL, "m_pbtnScan == NULL");
            exit(1);
        }
        m_pbtnCancel = static_cast<CButtonUI *>(m_pm.FindControl(_T("btnCancel")));
        if (m_pbtnCancel == NULL) {
            logline(LOG::LEVEL_FATAL, "m_pbtnCancel == NULL");
            exit(1);
        }

        m_phlProgress = static_cast<CHorizontalLayoutUI *>(m_pm.FindControl(_T("hlProgress")));
        if (m_phlProgress == NULL) {
            logline(LOG::LEVEL_FATAL, "m_phlProgress == NULL");
            exit(1);
        }

        m_pprgScan = static_cast<CProgressUI *>(m_pm.FindControl(_T("prgScan")));
        if (m_pprgScan == NULL) {
            logline(LOG::LEVEL_FATAL, "m_pprgSearch == NULL");
            exit(1);
        }

        m_plstLogs = static_cast<CListUI *>(m_pm.FindControl(_T("lstLogs")));
        if (m_plstLogs == NULL) {
            logline(LOG::LEVEL_FATAL, "m_plstLogs == NULL");
            exit(1);
        }
        m_pprgScan->SetValue(0);
        return 0;

    } else if (uMsg == WM_DESTROY) {
        logline(LOG::LEVEL_INFO, "MSG#%d: WM_DESTROY", m_gEvtNum++);
        ::PostQuitMessage(0);
    } else if (uMsg == WM_NCCALCSIZE) {
        logline(LOG::LEVEL_INFO, "MSG#%d: WM_NCCALCSIZE", m_gEvtNum++);
    } else if (uMsg == WM_NCACTIVATE) {
        logline(LOG::LEVEL_INFO, "MSG#%d: WM_NCACTIVATE", m_gEvtNum++);
    } else if (uMsg == WM_NCPAINT) {
        logline(LOG::LEVEL_INFO, "MSG#%d: WM_NCPAINT", m_gEvtNum++);
    } else if (uMsg == WM_PAINT) {
        m_pprgScan->SetValue(100);
    } else{
        //logline(LOG::LEVEL_INFO, "MSG#%d: type=%u", m_gEvtNum++);
    }

    LRESULT lRes = 0;
    if (m_pm.MessageHandler(uMsg, wParam, lParam, lRes)) return lRes;
    return CWindowWnd::HandleMessage(uMsg, wParam, lParam);
}

void Frame::attachEvent(HANDLE hEvent) {
    m_event2find = hEvent;
}

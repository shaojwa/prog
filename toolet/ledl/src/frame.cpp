

#include "frame.h"

#include "Shlwapi.h"
#include "shlobj.h"

int Frame::m_gEvtNum = 0;

#define DIALOG_TITLE         _T("flog")

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
        if (msg.pSender == m_pbtnMin) {
            SendMessage(WM_SYSCOMMAND, SC_MINIMIZE, 0);

        } else if (msg.pSender == m_pbtnClose) {
            PostMessage(WM_CLOSE, NULL, NULL);

        } else if (msg.pSender == m_pbtnExtractCust || 
            msg.pSender == m_pbtnExtractAuto) {

            m_plblExtractState->SetText(_T("日志提取中请稍后..."));
            m_plblExtractState->SetFont(8);
            m_plblExtractState->SetTextColor(0xFFFFFFFF);
            int count = m_ptlMainPanel->GetCount();
            m_ptlMainPanel->SelectItem(count - 1);
            m_phlControlPanel->SetVisible(true);

            if (msg.pSender == m_pbtnExtractCust) {
                LPCTSTR pPattern = m_pedtPattern->GetText().GetData();
                LPCTSTR pSrc = m_pedtSrc->GetText().GetData();
                LPCTSTR pDest = m_pedtDst->GetText().GetData();
                if (_tcslen(pPattern) == 0) {
                    MessageBox(this->GetHWND(), PROMPT_PATTERN_EMPTY, DIALOG_TITLE, MB_OK|MB_ICONERROR);
                } else if (!::PathFileExists(pSrc)) {
                    MessageBox(this->GetHWND(), PROMPT_SRC_INVALID, DIALOG_TITLE, MB_OK|MB_ICONERROR);
                } else if(!::PathFileExists(pDest)) {
                    MessageBox(this->GetHWND(), PROMPT_SRC_INVALID, DIALOG_TITLE, MB_OK|MB_ICONERROR);
                } else {
                    m_pConfig->setPattern(m_pedtPattern->GetText().GetData());
                    m_pConfig->setSrc(m_pedtSrc->GetText().GetData());
                    m_pConfig->setDst(m_pedtDst->GetText().GetData());
                    m_pConfig->setExtractType(EXTRACT_TYPE_CUSTOM);
                    SetEvent(m_hExtractEvent);

                }
            } else {
                 m_pConfig->setExtractType(EXTRACT_TYPE_AUTO);
                 SetEvent(m_hExtractEvent);
            }
        } else if (msg.pSender == m_pbtnStop) {
            printf("click stop button\n");

        } else if (msg.pSender == m_pbtnSrcBrowse) {
            browseFile(m_pedtSrc);

        } else if (msg.pSender == m_pbtnDstBrowse) {
            browseFile(m_pedtDst);
        } else if (msg.pSender == m_pbtnAdvance) {
            int count = m_ptlExtractType->GetCount();
            m_ptlExtractType->SelectItem(count -1);

        } else if(msg.pSender == m_pbtnCloseAdvance) {
            m_ptlExtractType->SelectItem(0);
        } else if (msg.pSender == m_pbtnStop) {

        } else if (msg.pSender == m_pbtnBack) {
            m_ptlMainPanel->SelectItem(0);
            m_phlControlPanel->SetVisible(false);
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

    if (uMsg == WM_CREATE ) {
        printf("Nsg#%d: WM_CREATE\n", m_gEvtNum++);
        LONG styleValue = ::GetWindowLong(GetHWND(), GWL_STYLE);
        styleValue &= ~WS_CAPTION;
        ::SetWindowLong(GetHWND(), GWL_STYLE, styleValue);
        m_pm.Init(m_hWnd);
        CDialogBuilder builder;
        CControlUI * pRoot = builder.Create(_T("frame.xml"), NULL, NULL, &m_pm);
        ASSERT(pRoot && "Failed to parse xml");
        m_pm.AttachDialog(pRoot);
        m_pm.AddNotifier(this);

        //标题栏相关
        m_phlTitleBar = static_cast<CHorizontalLayoutUI *>(m_pm.FindControl(_T("hlTitleBar")));
        if (NULL == m_phlTitleBar) { printf("ERROR: m_phlTitleBar == NULL\n"); exit(1); }

        m_plblProductName = static_cast<CLabelUI *>(m_pm.FindControl(_T("lblProductName")));
        if (NULL == m_plblProductName) { printf("ERROR: m_plblProductName == NULL\n"); exit(1); }

        m_pbtnMin = static_cast<CButtonUI *>(m_pm.FindControl(_T("btnMin")));
        if (NULL == m_pbtnMin) { printf("ERROR: m_pbtnMin == NULL\n"); exit(1); }

        m_pbtnMax = static_cast<CButtonUI *>(m_pm.FindControl(_T("btnMax")));
        if (NULL == m_pbtnMax) { printf("ERROR: m_pbtnMax == NULL\n"); exit(1); }

        m_pbtnClose = static_cast<CButtonUI *>(m_pm.FindControl(_T("btnClose")));
        if (NULL == m_pbtnClose) { printf("ERROR: m_pbtnClose == NULL\n"); exit(1); }

        m_plblToolName = static_cast<CButtonUI *>(m_pm.FindControl(_T("lblToolName")));
        if (NULL == m_plblToolName) { printf("ERROR: m_plblToolName == NULL\n"); exit(1); }

        //控制面板相关
        m_phlControlPanel = static_cast<CHorizontalLayoutUI *>(m_pm.FindControl(_T("hlControlPanel")));
        if (NULL == m_phlControlPanel) { printf("ERROR: m_phlContrlPanel == NULL\n"); exit(1); }

        m_plblExtractState = static_cast<CLabelUI *>(m_pm.FindControl(_T("lblExtractState")));
        if (NULL == m_plblExtractState) { printf("ERROR: m_plblExtractState == NULL\n"); exit(1); }

        m_pbtnStop = static_cast<CButtonUI *>(m_pm.FindControl(_T("btnStop")));
        if (NULL == m_pbtnStop) { printf("ERROR: m_pbtnStop == NULL\n"); exit(1); }

        m_pbtnBack = static_cast<CButtonUI *>(m_pm.FindControl(_T("btnBack")));
        if (NULL == m_pbtnBack) { printf("ERROR: m_pbtnBack == NULL\n"); exit(1); }

        //主面板
        m_ptlMainPanel = static_cast<CTabLayoutUI *>(m_pm.FindControl(_T("tlMainPanel")));
        if (NULL == m_ptlMainPanel) { printf("ERROR: m_ptlMainPanel == NULL\n"); exit(1); }

        m_phlOptions = static_cast<CHorizontalLayoutUI *>(m_pm.FindControl(_T("hlOptions")));
        if (NULL == m_phlOptions) { printf("ERROR: m_pvlOptions == NULL\n"); exit(1); }

        m_ptlExtractType =  static_cast<CTabLayoutUI *>(m_pm.FindControl(_T("tlExtractType")));
        if (NULL == m_ptlExtractType) { printf("ERROR: m_ptlExtractType == NULL\n"); exit(1); }

        m_pbtnExtractAuto = static_cast<CButtonUI *>(m_pm.FindControl(_T("btnExtractAuto")));
        if (NULL == m_pbtnExtractAuto) { printf("ERROR: m_pbtnExtractAuto == NULL\n"); exit(1); }

        m_pbtnAdvance = static_cast<CButtonUI *>(m_pm.FindControl(_T("btnAdvance")));
        if (NULL == m_pbtnAdvance) { printf("ERROR: m_pbtnAdvance == NULL\n"); exit(1); }

        m_pbtnCloseAdvance = static_cast<CButtonUI *>(m_pm.FindControl(_T("btnCloseAdvance")));
        if (NULL == m_pbtnCloseAdvance) { printf("ERROR: m_pbtnCloseAdvance == NULL\n"); exit(1); }

        m_pedtPattern = static_cast<CEditUI *>(m_pm.FindControl(_T("edtPattern")));
        if (NULL == m_pedtPattern) { printf("ERROR: m_pedtPattern == NULL\n"); exit(1); }

        m_pedtSrc = static_cast<CEditUI *>(m_pm.FindControl(_T("edtSrc")));
        if (NULL == m_pedtSrc) { printf("ERROR: m_pedtSrc == NULL\n"); exit(1); }

        m_pedtDst = static_cast<CEditUI *>(m_pm.FindControl(_T("edtDst")));
        if (NULL == m_pedtDst) { printf("ERROR: m_pedtDst == NULL\n"); exit(1); }

        m_pbtnSrcBrowse = static_cast<CButtonUI *>(m_pm.FindControl(_T("btnSrcBrowse")));
        if (NULL == m_pbtnSrcBrowse) { printf("ERROR: m_pbtnSrcBrowse == NULL\n"); exit(1); }

        m_pbtnDstBrowse = static_cast<CButtonUI *>(m_pm.FindControl(_T("btnDstBrowse")));
        if (NULL == m_pbtnDstBrowse) { printf("ERROR: m_pbtnDstBrowse == NULL\n"); exit(1); }

        m_pbtnExtractCust = static_cast<CButtonUI *>(m_pm.FindControl(_T("btnExtract")));
        if (NULL == m_pbtnExtractCust) { printf("ERROR: m_pbtnExtract == NULL\n"); exit(1); }

        //系统日志
        m_phlProcess = static_cast<CHorizontalLayoutUI *>(m_pm.FindControl(_T("hlProcess")));
        if (NULL == m_phlProcess) { printf("ERROR: m_phlProcess == NULL\n"); exit(1); }
        m_plblProcessState = static_cast<CLabelUI *>(m_pm.FindControl(_T("lblProcessState")));
        if (NULL == m_plblProcessState) { printf("ERROR: m_plblProcessState == NULL\n"); exit(1); }

        m_phlOper = static_cast<CHorizontalLayoutUI *>(m_pm.FindControl(_T("hlOper")));
        if (NULL == m_phlOper) { printf("ERROR: m_phlOper == NULL\n"); exit(1); }
        m_plblOperState = static_cast<CLabelUI *>(m_pm.FindControl(_T("lblOperState")));
        if (NULL == m_plblOperState) { printf("ERROR: m_plblOperState == NULL\n"); exit(1); }

        //服务日志
        m_phlWeb = static_cast<CHorizontalLayoutUI *>(m_pm.FindControl(_T("hlWeb")));
        if (NULL == m_phlWeb) { printf("ERROR: m_phlWeb == NULL\n"); exit(1); }
        m_plblWebState = static_cast<CLabelUI *>(m_pm.FindControl(_T("lblWebState")));
        if (NULL == m_plblWebState) { printf("ERROR: m_plblWebState == NULL\n"); exit(1); }

        m_phlSmb = static_cast<CHorizontalLayoutUI *>(m_pm.FindControl(_T("hlSmb")));
        if (NULL == m_phlSmb) { printf("ERROR: m_phlSmb == NULL\n"); exit(1); }
        m_plblSmbState = static_cast<CLabelUI *>(m_pm.FindControl(_T("lblSmbState")));
        if (NULL == m_plblSmbState) { printf("ERROR: m_plblSmbState == NULL\n"); exit(1); }

        m_phlFtp = static_cast<CHorizontalLayoutUI *>(m_pm.FindControl(_T("hlFtp")));
        if (NULL == m_phlFtp) { printf("ERROR: m_phlFtp == NULL\n"); exit(1); }
        m_plblFtpState = static_cast<CLabelUI *>(m_pm.FindControl(_T("lblFtpState")));
        if (NULL == m_plblFtpState) { printf("ERROR: m_plblFtpState == NULL\n"); exit(1); }


        m_phlSsh = static_cast<CHorizontalLayoutUI *>(m_pm.FindControl(_T("hlSsh")));
        if (NULL == m_phlSsh) { printf("ERROR: m_phlSsh == NULL\n"); exit(1); }
        m_plblSshState = static_cast<CLabelUI *>(m_pm.FindControl(_T("lblSshState")));
        if (NULL == m_plblSshState) { printf("ERROR: m_plblSshState == NULL\n"); exit(1); }

        m_phlDatabase = static_cast<CHorizontalLayoutUI *>(m_pm.FindControl(_T("hlDatabase")));
        if (NULL == m_phlDatabase) { printf("ERROR: m_phlDatabase == NULL\n"); exit(1); }
        m_plblSshState = static_cast<CLabelUI *>(m_pm.FindControl(_T("lblSshState")));
        if (NULL == m_plblDatabaseState) { printf("ERROR: m_plblDatabaseState == NULL\n"); exit(1); }

        m_ptlMainPanel->SelectItem(0);
        return 0;

    } else if (uMsg == WM_DESTROY) {
        printf("Msg#%d: WM_DESTROY\n", m_gEvtNum++);
        ::PostQuitMessage(0);
    } else if (uMsg == WM_NCCALCSIZE) {
        printf("Msg#%d: WM_NCCALCSIZE\n", m_gEvtNum++);
        return 0;
    } else if (uMsg == WM_NCACTIVATE) {
        printf("Msg#%d: WM_NCACTIVATE\n", m_gEvtNum++);
        if (!::IsIconic(m_hWnd)) {
            return (wParam == 0)? TRUE:FALSE;
        }
    } else if (uMsg == WM_NCPAINT) {
        printf("Msg#%d: WM_NCPAINT\n", m_gEvtNum++);
        return 0;

    } else if (uMsg == WM_PAINT) {
        int prog = m_pConfig->getProgress();

    } else if (uMsg == WM_NCHITTEST) {
        //通过对NCHITTEST消息的处理来移动窗口
        POINT pt;
        pt.x = GET_X_LPARAM(lParam);
        pt.y = GET_Y_LPARAM(lParam);
        ::ScreenToClient(GetHWND(), &pt);
        RECT titlePos = m_phlTitleBar->GetPos();
        RECT minPos = m_pbtnMin->GetPos();
        if (pt.x > 0 && pt.x < minPos.left && pt.y > 0 && pt.y < titlePos.bottom) {
            return HTCAPTION;
        }
    } else if (USER_MSG_TASK_STATE == uMsg) {
        ETaskType type = (ETaskType)wParam;
        ETaskState state = (ETaskState)lParam;
        UpdateTaskStateUI(type, state);
    } else{
        printf("Msg#%d: type=%u \n", m_gEvtNum++, uMsg);
    }

    LRESULT lRes = 0;
    if (m_pm.MessageHandler(uMsg, wParam, lParam, lRes)) return lRes;
    return CWindowWnd::HandleMessage(uMsg, wParam, lParam);
}

void Frame::attachEvent(HANDLE hExtractEvent) {
    m_hExtractEvent = hExtractEvent;
}


int Frame::attachConfig(CConfig * pConfig) {
    if(NULL == pConfig) {
        return 1;
    }
    m_pConfig = pConfig;
    return 0;
}


bool Frame::browseFile(CEditUI *pedit) {
    BOOL ret = FALSE;
    BROWSEINFO browse;
    TCHAR szPath[MAX_PATH]={0};
    browse.hwndOwner = GetHWND();
    browse.pszDisplayName = szPath;
    browse.pidlRoot = NULL;
    browse.lpszTitle = _T("");
    browse.ulFlags = BIF_EDITBOX;
    browse.lpfn = NULL;
    browse.lParam = 0;
    browse.iImage = 0;

    LPITEMIDLIST pIDList = SHBrowseForFolder(&browse);
    if (pIDList) {
        SHGetPathFromIDList(pIDList, szPath);
         pedit->SetText(szPath);
    }
    return true;
}

void Frame::UpdateTaskStateUI(const ETaskType type, const ETaskState state)
{
    CHorizontalLayoutUI *hlState = NULL;
    CLabelUI *lblState  = NULL;
    switch (type) {
        case TASK_TYPE_SYS_PROCESSES:
            hlState = m_phlProcess;
            lblState = m_plblProcessState;
            break;
        case TASK_TYPE_SYS_OPERATION:
            hlState = m_phlOper;
            lblState = m_plblOperState;
            break;
        case TASK_TYPE_SVC_WEB:
            hlState = m_phlWeb;
            lblState = m_plblWebState;
            break;
        case TASK_TYPE_SVC_SMB:
            hlState = m_phlSmb;
            lblState = m_plblSmbState;
            break;
        case TASK_TYPE_SVC_FTP:
            hlState = m_phlFtp;
            lblState = m_plblFtpState;
            break;
        case TASK_TYPE_SVC_SSH:
            hlState = m_phlSsh;
            lblState = m_plblSshState;
            break;
        case TASK_TYPE_SVC_DATABASE:
            hlState = m_phlDatabase;
            lblState = m_plblDatabaseState;
            break;
        default:
            break;
    }


    if (TASK_STATE_INIT == state || TASK_STATE_PENDING == state) {
        hlState->SetBkImage(_T("file='task.png' source='204,0,255,52'"));
        lblState->SetText(_T("未完成"));
        lblState->SetTextColor(0xFFF10909);

    } else if (TASK_STATE_INPROCESS == state) {
        hlState->SetBkImage(_T("file='task.png' source='153,0,204,52'"));
        lblState->SetText(_T("提取中"));
        lblState->SetTextColor(0xFFF5F5F5);

    } else if (TASK_STATE_FINISHED == state) {
        hlState->SetBkImage(_T("file='task.png' source='102,0,153,52'"));
        lblState->SetText(_T("已完成"));
        lblState->SetTextColor(0xFFF5F5F5);
    }
}

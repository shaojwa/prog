
#include "include/config.h"


const QString Config::FILENAME_SHELLFIND = "find.out";
const QString Config::TitleLine = " 日志提取工具 v1.0";
const QString Config::StateLine = " 版权所有(C) 2007-2016 v1.0";
const QString Config::FrameStyleSheet = "QFrame { background: #015AAA }";

const QString Config::TitleBarStyleSheet =
        "QWidget { background: #015AAA }"
        "QLabel { color: #FFFFFF }"
        "QPushButton { border :0px;}";

const QString Config::TitleMinBtnStyle =
        "QPushButton { background-image: url(:/img/btnmin); }"
        "QPushButton:hover { background-image: url(:/img/btnminh);}";

const QString Config::TitleCloseBtnStyle =
        "QPushButton { background-image: url(:/img/btnclose); }"
        "QPushButton:hover { background-image: url(:/img/btncloseh);}";


const QString Config::ToolBarTxtKey = "一键提取";
const QString Config::ToolBarPathKey = ":/img/onekey";
const QString Config::ToolBarTxtCust = "定制提取";
const QString Config::ToolBarPathCust = ":/img/cust";
const QString Config::ToolBarStyleSheet = "QWidget {}";

const QString Config::ToolButtonStyleNomal =
        "QToolButton { border: 0px;}"
        "QToolButton:hover { background-color: #98B8E9; }";

const QString Config::ToolButtonStyleSelect =
        "QToolButton { border: 0px; background-color: #98B8E9;}" ;


const QString Config::PanelTxtBtnExtractStart = "提取日志";
const QString Config::PanelTxtBtnExtractCancel = "取消";
const QString Config::PanelTxtLblExtractState = "提取状态：";
const QString Config::PanelTxtLblExtractResult = "未提取";
const QString Config::PanelTxtExtractInprocess = "正在提取日志...";
const QString Config::PanelTxtExtractCanceled = "日志提取被取消！";
const QString Config::PanelTxtExtractFinished = "日志提取完成！";
const QString Config::PanelTxtNoExtractLogs = "没有相关日志需要提取！";
const QString Config::PanelTxtExceptionOnExtract = "提取过程中出现异常！";


const QString Config::PanelTxtLblSearchPath  = "搜索路径：";
const QString Config::PanelTxtLedtSearchPath = "";
const QString Config::PanelTxtBtnSearchBrowse = "浏览";
const QString Config::PanelTxtLblPattern = "匹配格式：";
const QString Config::PanelTxtLedtPattern = "";
const QString Config::PanelTxtLblSearchState = "搜索状态：";
const QString Config::PanelTxtLblSearchResult = "未开始";
const QString Config::PanelTxtBtnClearLogs = "清空列表";
const QString Config::PanelTxtBtnSearchStart = "开始搜索";
const QString Config::PanelTxtBtnSearchCancel = "取消搜索";
const QString Config::PanelTxtLblBackupPath = "备份路径：";
const QString Config::PanelTxtLedtBackupPath = "";
const QString Config::PanelTxtBtnBackupBrowse = "浏览";
const QString Config::PanelTxtLblBackupState = "备份状态：";
const QString Config::PanelTxtLblBackupInfo = "未开始";
const QString Config::PanelTxtBtnBackupStart = "开始备份";
const QString Config::PanelTxtBtnBackupCancel = "取消备份";


const QString Config::PanelTxtAttention = "注意：";
const QString Config::PanelTxtNoSearchPath = "请填写搜索路径！";
const QString Config::PanelTxtInvalidSearchPath = "请确认搜索路径是否存在！";
const QString Config::PanelTxtNoBackupPath = "请填写备份路径。";
const QString Config::PanelTxtInvalidBackupPath = "请确认备份路径是否存在！";
const QString Config::PanelTxtNoPattern = "请填写匹配格式！";
const QString Config::PanelTxtNoFoundLogs = "没有搜索到匹配日志！";
const QString Config::PanelTxtExceptionOnSearch = "搜索过程中出现异常！";
const QString Config::PanelTxtSearchInprocess = "正在搜索...";

const QString Config::PanelTxtBackupInprocess = "正在备份...";
const QString Config::PanelTxtBackupSuccess = "备份完成！";
const QString Config::PanelTxtBackupFailure = "备份失败，请检查目录权限等相关配置。";
const QString Config::PanelTxtBackupCanceled = "备份被取消！";

const QString Config::PanelWidgetStyle =
        "QWidget { background: #98B8E9; color: #5c5c5c; }"
        "QLabel { color:#00162D; }"
        "QPushButton { height: 24px; width:48px; border:0px; color: white; background: #015AAA }"
        "QPushButton:hover { background: #1986C7 }"
        "QLineEdit { height: 24px; border: 1px solid #1986C7; color: black; background-color: white;}"
        "QLineEdit:hover {border-color: #015AAA; }"
        "QListWidget { border: 1px solid #015AAA; }";

const QString Config::PanelTreeWidgetStyle =
        "QTreeWidget { border: 1px solid #015AAA; color: #00162D }"
        "QTreeWidget::item { height: 24px;}";
const QString Config::PanelHeaderStyle =
        "QHeaderView { height:32px; color:#00162D; border:0px }";

const QString Config::StateBarStyleSheet =
        "QWidget { height: 32px; background: #015AAA;}"
        "QLabel { height: 32px; color: white;}";


//#325BC7 紫蓝
//#015AAA 深蓝
//#1986C7 浅蓝
//#98B8E9 灰蓝
//#D9E4F1 浅灰
//#7092BE 淡灰
//#5c5c5c 深灰
//#00162D 黑蓝


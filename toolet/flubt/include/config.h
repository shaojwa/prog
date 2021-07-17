#ifndef CONDIG_H
#define CONDIG_H

#include <QString>

class Config {
public:    
    // others
    static const QString FILENAME_SHELLFIND;

    // global configs
    static const QString TitleLine;
    static const QString StateLine;

    // frame configs
    static const int FrameWidth = 800;
    static const int FrameHeight = 600;
    static const int DefaultFontSize = 10;
    static const QString FrameStyleSheet;


    // titlebar configs
    static const int TitleBarHeight = 32;
    static const int TitleIconHeight = 24;
    static const int TitleIconWidth = 24;
    static const int TitleBarFontSize = 10;
    static const int TitleBarMinBtnWidth = 30;
    static const int TitleBarMinBtnHeight = 15;
    static const int TitleBarCloseBtnWidth = 30;
    static const int TitleBarCloseBtnHeight = 15;
    static const int TitleBarButtonSpace = 8;
    static const QString TitleBarStyleSheet;
    static const QString TitleMinBtnStyle;
    static const QString TitleCloseBtnStyle;

    // toolbar configs
    static const int ToolBarHeight = 96;
    static const int ToolBarButtonWidth = 96;
    static const int ToolBarButtonHeight = 96;
    static const int ToolBarButtonSpace = 8;
    static const int ToolBarIconSize = 64;
    static const int ToolBarFontSize = 10;
    static const QString ToolBarTxtKey;
    static const QString ToolBarPathKey;
    static const QString ToolBarTxtCust;
    static const QString ToolBarPathCust;
    static const QString ToolBarStyleSheet;
    static const QString ToolButtonStyleNomal;
    static const QString ToolButtonStyleSelect;

    //content configs
    static const QString PanelTxtBtnExtractStart;
    static const QString PanelTxtBtnExtractCancel;
    static const QString PanelTxtLblExtractState;
    static const QString PanelTxtLblExtractResult;
    static const QString PanelTxtExtractInprocess;
    static const QString PanelTxtExtractCanceled;
    static const QString PanelTxtExtractFinished;
    static const QString PanelTxtNoExtractLogs;
    static const QString PanelTxtExceptionOnExtract;


    static const QString PanelTxtLblSearchPath;
    static const QString PanelTxtLedtSearchPath;
    static const QString PanelTxtBtnSearchBrowse;
    static const QString PanelTxtLblPattern;
    static const QString PanelTxtLedtPattern;
    static const QString PanelTxtLblSearchState;
    static const QString PanelTxtLblSearchResult;
    static const QString PanelTxtBtnClearLogs;
    static const QString PanelTxtBtnSearchStart;
    static const QString PanelTxtBtnSearchCancel;
    static const QString PanelTxtLblBackupPath;
    static const QString PanelTxtLedtBackupPath;
    static const QString PanelTxtBtnBackupBrowse;
    static const QString PanelTxtLblBackupState;
    static const QString PanelTxtLblBackupInfo;
    static const QString PanelTxtBtnBackupStart;
    static const QString PanelTxtBtnBackupCancel;

    static const QString PanelTxtAttention;
    static const QString PanelTxtNoSearchPath;
    static const QString PanelTxtInvalidSearchPath;
    static const QString PanelTxtNoBackupPath;
    static const QString PanelTxtInvalidBackupPath;
    static const QString PanelTxtNoPattern;
    static const QString PanelTxtNoFoundLogs;
    static const QString PanelTxtExceptionOnSearch;
    static const QString PanelTxtSearchInprocess;
    static const QString PanelTxtBackupInprocess;
    static const QString PanelTxtBackupSuccess;
    static const QString PanelTxtBackupFailure;
    static const QString PanelTxtBackupCanceled;

    static const QString PanelWidgetStyle;
    static const QString PanelTreeWidgetStyle;
    static const QString PanelHeaderStyle;


    // statebar configs
    static const int StateBarHeight = 32;
    static const int StateBarFontSize = 10;
    static const QString StateBarStyleSheet;

};
#endif // CONDIG_H

#include "include/panelwin.h"
#include "include/config.h"

#include <QHeaderView>


PanelWin::PanelWin(QWidget *parent): QFrame(parent)
{ 

    _stack = new QStackedLayout();
    setLayout(_stack);

    // add pages
    _keyPage = new QWidget();
    _keyPage->setStyleSheet(Config::PanelWidgetStyle);
    _custPage = new QWidget();
    _custPage->setStyleSheet(Config::PanelWidgetStyle);

    _stack->addWidget(_keyPage);
    _stack->addWidget(_custPage);
    _stack->setCurrentIndex(0);


    _onekeylayout = new QGridLayout(_keyPage);
    _onekeylayout->setSpacing(5);
    _onekeylayout->setContentsMargins(10, 10, 10, 10);
    _onekeylayout->setRowMinimumHeight(0, 32);

    //onekey pages
    _trwLogSelect = new QTreeWidget(this);
    _trwLogSelect->setStyleSheet(Config::PanelTreeWidgetStyle);
    _onekeylayout->addWidget(_trwLogSelect, 0, 0, 4, 9);
    _trwLogSelect->setHeaderHidden(true);

    _twiSyslog = new QTreeWidgetItem();
    _trwLogSelect->addTopLevelItem(_twiSyslog);
    _twiSvclog = new QTreeWidgetItem();
    _trwLogSelect->addTopLevelItem(_twiSvclog);


    _twiSyslog->setSelected(true);
    _twiSyslog->setText(0, "系统日志");
    _twiProc = new QTreeWidgetItem();
    _twiProc->setText(0, "进程日志");
    _twiUser = new QTreeWidgetItem();
    _twiUser->setText(0, "操作日志");
    _twiSyslog->addChild(_twiProc);
    _twiSyslog->addChild(_twiUser);

    _twiSvclog->setSelected(true);
    _twiSvclog->setText(0, "服务日志");
    _twiWeb = new QTreeWidgetItem();
    _twiWeb->setText(0, "Web服务日志");
    _twiSmb = new QTreeWidgetItem();
    _twiSmb->setText(0, "SMB服务日志");
    _twiFtp = new QTreeWidgetItem();
    _twiFtp->setText(0, "FTP服务日志");
    _twiSsh = new QTreeWidgetItem();
    _twiSsh->setText(0, "SSH服务日志");
    _twiSvclog->addChild(_twiWeb);
    _twiSvclog->addChild(_twiSmb);
    _twiSvclog->addChild(_twiFtp);
    _twiSvclog->addChild(_twiSsh);

    _lblExtractState = new QLabel(this);
    _lblExtractState->setText(Config::PanelTxtLblExtractState);
    _onekeylayout->addWidget(_lblExtractState, 8, 0, 1, 1);
    _lblExtractResult = new QLabel(this);
    _lblExtractResult->setText(Config::PanelTxtLblExtractResult);
    _onekeylayout->addWidget(_lblExtractResult, 8, 1, 1, 7);
    _btnExtractStart = new QPushButton(this);
    _btnExtractStart->setText(Config::PanelTxtBtnExtractStart);
    _onekeylayout->addWidget(_btnExtractStart, 8, 7, 1, 1);
    _btnExtractCancel = new QPushButton(this);
    _btnExtractCancel->setText(Config::PanelTxtBtnExtractCancel);
    _onekeylayout->addWidget(_btnExtractCancel, 8, 8, 1, 1);



    // customise pages
    _custlayout = new QGridLayout(_custPage);
    _custlayout->setSpacing(5);
    _custlayout->setContentsMargins(10, 10, 10, 10);
    _custlayout->setRowMinimumHeight(0, 32);
    _lblSearchPath = new QLabel(this);
    _lblSearchPath->setText(Config::PanelTxtLblSearchPath);
    _custlayout->addWidget(_lblSearchPath, 0, 0, 1, 1);
    _ledtSearchPath = new QLineEdit(this);
    _custlayout->addWidget(_ledtSearchPath, 0, 1, 1, 8);
    _btnSearchBrowse = new QPushButton(this);
    _btnSearchBrowse->setText(Config::PanelTxtBtnSearchBrowse);
    _custlayout->addWidget(_btnSearchBrowse, 0, 9, 1, 1);


    _custlayout->setRowMinimumHeight(1,30);
    _lblPattern = new QLabel(this);
    _lblPattern->setText(Config::PanelTxtLblPattern);
    _custlayout->addWidget(_lblPattern, 1, 0, 1, 1);
    _ledtPattern = new QLineEdit(this);
    _custlayout->addWidget(_ledtPattern, 1, 1, 1, 8);

    _custlayout->setRowMinimumHeight(2,30);
    _lblSearchState = new QLabel(this);
    _lblSearchState->setText(Config::PanelTxtLblSearchState);
    _custlayout->addWidget(_lblSearchState, 2, 0, 1, 1);
    _lblSearchResult = new QLabel(this);
    _lblSearchResult->setText(Config::PanelTxtLblSearchResult);
    _custlayout->addWidget(_lblSearchResult, 2, 1, 1, 7);
    _btnSearchStart = new QPushButton(this);
    _btnSearchStart->setText(Config::PanelTxtBtnSearchStart);
    _custlayout->addWidget(_btnSearchStart, 2, 8, 1, 1);
    _btnSearchCancel = new QPushButton(this);
    _btnSearchCancel->setText(Config::PanelTxtBtnSearchCancel);
    _custlayout->addWidget(_btnSearchCancel, 2, 9, 1, 1);

    _lstLogs = new QListWidget(this);
    _custlayout->addWidget(_lstLogs, 3, 1, 8, 8);
    _btnClearLogs = new QPushButton(this);

    _custlayout->setRowMinimumHeight(10,30);
    _btnClearLogs->setText(Config::PanelTxtBtnClearLogs);
    _custlayout->addWidget(_btnClearLogs, 10, 9, 1, 1);

    _custlayout->setRowMinimumHeight(11, 30);
    _lblBackupPath =  new QLabel(this);
    _lblBackupPath->setText(Config::PanelTxtLblBackupPath);
    _custlayout->addWidget(_lblBackupPath, 11, 0, 1, 1);
    _ledtBackupPath = new QLineEdit(this);
    _ledtBackupPath->setText(Config::PanelTxtLedtBackupPath);
    _custlayout->addWidget(_ledtBackupPath, 11, 1, 1, 8);
    _btnBackupBrowse = new QPushButton(this);
    _btnBackupBrowse->setText(Config::PanelTxtBtnBackupBrowse);
    _custlayout->addWidget(_btnBackupBrowse, 11, 9, 1, 1);

    _custlayout->setRowMinimumHeight(12,30);
    _lblBackupState = new QLabel(this);   
    _lblBackupState->setText(Config::PanelTxtLblBackupState);
    _custlayout->addWidget(_lblBackupState, 12, 0, 1, 1);
    _lblBackupInfo = new QLabel(this);
    _lblBackupInfo->setText(Config::PanelTxtLblBackupInfo);
    _custlayout->addWidget(_lblBackupInfo, 12, 1, 1, 7);
    _btnBackupStart = new QPushButton(this);
    _btnBackupStart->setText(Config::PanelTxtBtnBackupStart);
    _custlayout->addWidget(_btnBackupStart, 12, 8, 1, 1);
    _btnBackupCancel = new QPushButton(this);
    _btnBackupCancel->setText(Config::PanelTxtBtnBackupCancel);
    _custlayout->addWidget(_btnBackupCancel, 12, 9, 1, 1);
}


void PanelWin::selectKey() {
    _stack->setCurrentIndex(0);
}


void PanelWin::selectCust() {
    _stack->setCurrentIndex(1);
}

#ifndef CONTENTWIDGET_H
#define CONTENTWIDGET_H


#include <QWidget>
#include <QLabel>
#include <QLineEdit>
#include <QPushButton>
#include <QListWidget>
#include <QTreeWidget>
#include <QTreeWidgetItem>
#include <QGridLayout>
#include <QStackedLayout>



class PanelWin: public QFrame
{
Q_OBJECT
public:
    PanelWin(QWidget *parent);

public slots:
    void selectKey();
    void selectCust();

public:

    QWidget *_keyPage;
    QWidget *_custPage;
    QStackedLayout *_stack;

    QGridLayout *_onekeylayout;
    QGridLayout *_custlayout;

    // onekey panel
    QTreeWidget * _trwLogSelect;
    QTreeWidgetItem *_twiSyslog;
    QTreeWidgetItem *_twiProc;
    QTreeWidgetItem *_twiUser;
    QTreeWidgetItem *_twiSvclog;
    QTreeWidgetItem *_twiWeb;
    QTreeWidgetItem *_twiSmb;
    QTreeWidgetItem *_twiFtp;
    QTreeWidgetItem *_twiSsh;
    QPushButton * _btnExtractStart;
    QPushButton * _btnExtractCancel;
    QLabel  *_lblExtractState;
    QLabel *_lblExtractResult;

    // customise panel
    QLabel *_lblSearchPath;
    QLineEdit *_ledtSearchPath;
    QPushButton *_btnSearchBrowse;
    QLabel *_lblPattern;
    QLineEdit *_ledtPattern;
    QLabel  *_lblSearchState;
    QLabel *_lblSearchResult;
    QPushButton *_btnSearchCancel;
    QPushButton *_btnSearchStart;

    //logs list
    QListWidget *_lstLogs;
    QPushButton *_btnClearLogs;

    //backup items
    QLabel *_lblBackupPath;
    QLineEdit *_ledtBackupPath;
    QPushButton *_btnBackupBrowse;
    QPushButton *_btnBackupCancel;
    QPushButton *_btnBackupStart;
    QLabel *_lblBackupState;
    QLabel *_lblBackupInfo;

};

#endif // CONTENTWIDGET_H

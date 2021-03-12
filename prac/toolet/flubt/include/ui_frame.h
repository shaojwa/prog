/********************************************************************************
** Form generated from reading UI file 'frame.ui'
**
** Created by: Qt User Interface Compiler version 5.6.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FRAME_H
#define UI_FRAME_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Frame
{
public:
    QAction *action_About;
    QWidget *centralWidget;
    QGridLayout *gridLayout;
    QSpacerItem *horizontalSpacer;
    QLabel *lblSearchState;
    QLabel *lblSearch;
    QFrame *line;
    QLineEdit *ledtSearchPath;
    QLabel *lblPattern;
    QPushButton *pbtnSearchBrowse;
    QLineEdit *ledtBackupPath;
    QPushButton *pbtnBackupBrowse;
    QLabel *lblBackup;
    QLineEdit *ledtPattern;
    QListWidget *lstLogs;
    QPushButton *pbtnSearchCancel;
    QPushButton *pbtnSearchStart;
    QPushButton *pbtnBackupCancel;
    QPushButton *pbtnBackupStart;
    QLabel *lblLogCount;
    QPushButton *pbtnClearLogs;
    QLabel *lblBackupState;
    QLabel *lblBackupInfo;
    QMenuBar *menuBar;
    QMenu *menu_File;
    QMenu *menu_Help;

    void setupUi(QMainWindow *Frame)
    {
        if (Frame->objectName().isEmpty())
            Frame->setObjectName(QStringLiteral("Frame"));
        Frame->resize(600, 400);
        Frame->setMinimumSize(QSize(600, 400));
        Frame->setMaximumSize(QSize(900, 600));
        action_About = new QAction(Frame);
        action_About->setObjectName(QStringLiteral("action_About"));
        action_About->setShortcutContext(Qt::WidgetShortcut);
        centralWidget = new QWidget(Frame);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        gridLayout = new QGridLayout(centralWidget);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer, 10, 4, 1, 1);

        lblSearchState = new QLabel(centralWidget);
        lblSearchState->setObjectName(QStringLiteral("lblSearchState"));
        lblSearchState->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);

        gridLayout->addWidget(lblSearchState, 4, 2, 1, 1);

        lblSearch = new QLabel(centralWidget);
        lblSearch->setObjectName(QStringLiteral("lblSearch"));

        gridLayout->addWidget(lblSearch, 0, 0, 1, 1);

        line = new QFrame(centralWidget);
        line->setObjectName(QStringLiteral("line"));
        line->setFrameShape(QFrame::HLine);
        line->setFrameShadow(QFrame::Sunken);

        gridLayout->addWidget(line, 13, 0, 1, 7);

        ledtSearchPath = new QLineEdit(centralWidget);
        ledtSearchPath->setObjectName(QStringLiteral("ledtSearchPath"));

        gridLayout->addWidget(ledtSearchPath, 0, 1, 1, 5);

        lblPattern = new QLabel(centralWidget);
        lblPattern->setObjectName(QStringLiteral("lblPattern"));

        gridLayout->addWidget(lblPattern, 1, 0, 1, 1);

        pbtnSearchBrowse = new QPushButton(centralWidget);
        pbtnSearchBrowse->setObjectName(QStringLiteral("pbtnSearchBrowse"));

        gridLayout->addWidget(pbtnSearchBrowse, 0, 6, 1, 1);

        ledtBackupPath = new QLineEdit(centralWidget);
        ledtBackupPath->setObjectName(QStringLiteral("ledtBackupPath"));

        gridLayout->addWidget(ledtBackupPath, 15, 1, 1, 5);

        pbtnBackupBrowse = new QPushButton(centralWidget);
        pbtnBackupBrowse->setObjectName(QStringLiteral("pbtnBackupBrowse"));

        gridLayout->addWidget(pbtnBackupBrowse, 15, 6, 1, 1);

        lblBackup = new QLabel(centralWidget);
        lblBackup->setObjectName(QStringLiteral("lblBackup"));

        gridLayout->addWidget(lblBackup, 15, 0, 1, 1);

        ledtPattern = new QLineEdit(centralWidget);
        ledtPattern->setObjectName(QStringLiteral("ledtPattern"));

        gridLayout->addWidget(ledtPattern, 1, 1, 1, 5);

        lstLogs = new QListWidget(centralWidget);
        lstLogs->setObjectName(QStringLiteral("lstLogs"));

        gridLayout->addWidget(lstLogs, 5, 1, 5, 5);

        pbtnSearchCancel = new QPushButton(centralWidget);
        pbtnSearchCancel->setObjectName(QStringLiteral("pbtnSearchCancel"));

        gridLayout->addWidget(pbtnSearchCancel, 4, 6, 1, 1);

        pbtnSearchStart = new QPushButton(centralWidget);
        pbtnSearchStart->setObjectName(QStringLiteral("pbtnSearchStart"));

        gridLayout->addWidget(pbtnSearchStart, 4, 5, 1, 1);

        pbtnBackupCancel = new QPushButton(centralWidget);
        pbtnBackupCancel->setObjectName(QStringLiteral("pbtnBackupCancel"));

        gridLayout->addWidget(pbtnBackupCancel, 17, 6, 1, 1);

        pbtnBackupStart = new QPushButton(centralWidget);
        pbtnBackupStart->setObjectName(QStringLiteral("pbtnBackupStart"));

        gridLayout->addWidget(pbtnBackupStart, 17, 5, 1, 1);

        lblLogCount = new QLabel(centralWidget);
        lblLogCount->setObjectName(QStringLiteral("lblLogCount"));

        gridLayout->addWidget(lblLogCount, 4, 3, 1, 1);

        pbtnClearLogs = new QPushButton(centralWidget);
        pbtnClearLogs->setObjectName(QStringLiteral("pbtnClearLogs"));

        gridLayout->addWidget(pbtnClearLogs, 9, 6, 1, 1);

        lblBackupState = new QLabel(centralWidget);
        lblBackupState->setObjectName(QStringLiteral("lblBackupState"));

        gridLayout->addWidget(lblBackupState, 17, 0, 1, 1);

        lblBackupInfo = new QLabel(centralWidget);
        lblBackupInfo->setObjectName(QStringLiteral("lblBackupInfo"));

        gridLayout->addWidget(lblBackupInfo, 17, 2, 1, 1);

        Frame->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(Frame);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 600, 21));
        menu_File = new QMenu(menuBar);
        menu_File->setObjectName(QStringLiteral("menu_File"));
        menu_Help = new QMenu(menuBar);
        menu_Help->setObjectName(QStringLiteral("menu_Help"));
        Frame->setMenuBar(menuBar);

        menuBar->addAction(menu_File->menuAction());
        menuBar->addAction(menu_Help->menuAction());
        menu_Help->addAction(action_About);

        retranslateUi(Frame);

        QMetaObject::connectSlotsByName(Frame);
    } // setupUi

    void retranslateUi(QMainWindow *Frame)
    {
        Frame->setWindowTitle(QApplication::translate("Frame", "Frame", 0));
        action_About->setText(QApplication::translate("Frame", "&About", 0));
        lblSearchState->setText(QApplication::translate("Frame", "\345\214\271\351\205\215\346\225\260\351\207\217\357\274\232", 0));
        lblSearch->setText(QApplication::translate("Frame", "\346\220\234\347\264\242\347\233\256\345\275\225\357\274\232", 0));
        lblPattern->setText(QApplication::translate("Frame", "\345\214\271\351\205\215\346\240\274\345\274\217\357\274\232", 0));
        pbtnSearchBrowse->setText(QApplication::translate("Frame", "\346\265\217\350\247\210", 0));
        pbtnBackupBrowse->setText(QApplication::translate("Frame", "\346\265\217\350\247\210", 0));
        lblBackup->setText(QApplication::translate("Frame", "\345\244\207\344\273\275\347\233\256\345\275\225\357\274\232", 0));
        pbtnSearchCancel->setText(QApplication::translate("Frame", "\345\217\226\346\266\210\346\220\234\347\264\242", 0));
        pbtnSearchStart->setText(QApplication::translate("Frame", "\345\274\200\345\247\213\346\220\234\347\264\242", 0));
        pbtnBackupCancel->setText(QApplication::translate("Frame", "\345\217\226\346\266\210\345\244\207\344\273\275", 0));
        pbtnBackupStart->setText(QApplication::translate("Frame", "\345\274\200\345\247\213\345\244\207\344\273\275", 0));
        lblLogCount->setText(QApplication::translate("Frame", "0", 0));
        pbtnClearLogs->setText(QApplication::translate("Frame", "\346\270\205\347\251\272\345\210\227\350\241\250", 0));
        lblBackupState->setText(QApplication::translate("Frame", "\345\244\207\344\273\275\347\212\266\346\200\201\357\274\232", 0));
        lblBackupInfo->setText(QApplication::translate("Frame", "\346\234\252\345\274\200\345\247\213", 0));
        menu_File->setTitle(QApplication::translate("Frame", "&File", 0));
        menu_Help->setTitle(QApplication::translate("Frame", "&Help", 0));
    } // retranslateUi

};

namespace Ui {
    class Frame: public Ui_Frame {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FRAME_H

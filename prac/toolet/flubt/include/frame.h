#ifndef FRAME_H
#define FRAME_H

#include "titlebar.h"
#include "toolbar.h"
#include "panelwin.h"
#include "statebar.h"
#include "extracter.h"
#include "searcher.h"
#include "backuper.h"
#include <QMainWindow>
#include <QVBoxLayout>


class Frame : public QFrame
{
    Q_OBJECT

public:
    QVBoxLayout *_layout;
    TitleBar *_titlebar;
    ToolBar *_toolbar;
    PanelWin *_panel;
    StateBar *_statebar;

public:
    explicit Frame(QWidget *parent = 0);
    ~Frame();
    void attach(Searcher *searcher);
    void attach(Backuper *backuper);
    void attach(Extracter *extracter);

public slots:
    void minwin();
    void closewin();
    void extractStart();
    void extractCancel();
    void searchStart();
    void searchCancel();
    void backupStart();
    void backupCancel();
    void clearLogs();
    void openFolder();
    void handleExtractResult(int);
    void handleSearchResult(int);
    void handleBackupResult(int);

signals:
    void onExtractStart();
    void onExtractCancel();
    void onSearchStart(QString searchPath, QString pattern);
    void onSearchCancel();
    void onBackupStart(QString backupPath);
    void onBackupCancel();

private:
    bool folderExists(QString path);  
};

#endif // FRAME_H

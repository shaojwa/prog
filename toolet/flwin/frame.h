#ifndef FRAME_H
#define FRAME_H

#include "searcher.h"
#include "backuper.h"
#include <QMainWindow>

namespace Ui {
class Frame;
}

class Frame : public QMainWindow
{
    Q_OBJECT

public:
    explicit Frame(QWidget *parent = 0);
    ~Frame();
    void attach(Searcher *searcher);
    void attach(Backuper *backuper);

public slots:
    void searchStart();
    void searchCancel();
    void backupStart();
    void backupCancel();
    void clearLogs();
    void openFolder();
    void handleSearchResult(int);
    void handleBackupResult(int);

signals:
    void sigSearchStart(QString searchPath, QString pattern);
    void sigBackupStart(QString backupPath);
    void sigSearchCancel();
    void sigBackupCancel();

private:
    bool folderExists(QString path);
    Ui::Frame *ui;    
};

#endif // FRAME_H

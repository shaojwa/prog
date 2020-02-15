#ifndef BACKUPER_H
#define BACKUPER_H

#include <QThread>
#include <QProcess>

class Backuper: public QObject {
    Q_OBJECT
    QThread thWorker;
public:
    Backuper();

public slots:
    void start(QString backupPath);
    void cancel();

signals:
    void sigFinished(int);

private:
QProcess *shellProc;

};

#endif // BACKUPER_H

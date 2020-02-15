#include "include/backuper.h"
#include "include/config.h"
#include <QMessageBox>
#include <QCoreApplication>


Backuper::Backuper() {
    this->moveToThread(&thWorker);
    shellProc = new QProcess();
    shellProc->moveToThread(&thWorker);
    thWorker.start();
}


void Backuper::start(QString backupPath) {
    qDebug("backuper::start(), tid = %p", QThread::currentThreadId());
    QProcess::ProcessState state = shellProc->state();
    if (state != QProcess::NotRunning) {
        return;
    }
    QStringList params;
    QString shellpath = QCoreApplication::applicationDirPath();
    QString script= shellpath + "/copylog.sh";
    params << script << backupPath;
    shellProc->start("/bin/bash", params);
    if (!shellProc->waitForFinished(-1)) {
        emit onFinished(-1);
    } else {
        if (0 != shellProc->exitCode()) {
            emit onFinished(-1);
        } else {
            emit onFinished(0);
        }
    }
    return;
}


void Backuper::cancel() {
    QProcess::ProcessState state = shellProc->state();
    if (state == QProcess::Running) {
        shellProc->kill();
        qDebug("killed shell process.");
    } else {
        qDebug("shell process is not running.");
    }
}

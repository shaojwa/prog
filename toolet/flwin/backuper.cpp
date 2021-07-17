#include "backuper.h"
#include "config.h"
#include <QMessageBox>


Backuper::Backuper() {
    this->moveToThread(&thWorker);
    shellProc = new QProcess();
    shellProc->moveToThread(&thWorker);
    thWorker.start();
}


void Backuper::start(QString backupPath) {
    qDebug("backuper::start(), tid = %u", (uint32_t)QThread::currentThreadId());
    QProcess::ProcessState state = shellProc->state();
    if (state != QProcess::NotRunning) {
        return;
    }
    QStringList params;
    params << "/c"  << "copylog.bat" << backupPath;
    shellProc->start("cmd.exe", params);
    if (!shellProc->waitForFinished(-1)) {
        qDebug("find log failed.");
        emit sigFinished(-1);
    } else {
        emit sigFinished(0);
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

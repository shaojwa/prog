#include "searcher.h"
#include "config.h"

#include <QMessageBox>
#include <QDebug>
#include <Qdir>


Searcher::Searcher() {
    this->moveToThread(&thWorker);
    shellProc = new QProcess();
    shellProc->moveToThread(&thWorker);
    thWorker.start();
}

void Searcher::start(QString searchPath, QString pattern) {
    qDebug("searcher::start, cur_tid = %u", (uint32_t)QThread::currentThreadId());
    QProcess::ProcessState state = shellProc->state();

    if (state != QProcess::NotRunning) {
        return;
    }    
    QStringList params;
    params << "/c"  << "findlog.bat" << searchPath << pattern;
    shellProc->start("cmd.exe", params);
    if (!shellProc->waitForFinished(-1)) {
        qDebug("find log failed.");
        return;
    }
    qDebug("finished finding logs");
    QFile file("list.out");
    _logcount = 0;
    if (!file.exists()) {
        _logcount = -1;
        qDebug("_logcount = %d", _logcount);
        emit sigFinished(_logcount);
        return;
    }

    if (!file.open(QIODevice::ReadOnly)) {
        _logcount = -1;
        qDebug("_logcount = %d", _logcount);
        emit sigFinished(_logcount);
        return;
    }

    while(!file.atEnd()) {
        file.readLine();
        _logcount++;
    }
    qDebug("_logcount = %d", _logcount);
    emit sigFinished(_logcount);
    return;
}

void Searcher::cancel() {
    QProcess::ProcessState state = shellProc->state();
    if (state == QProcess::Running) {
        shellProc->kill();
        qDebug("killed shell process.");
    } else {
        qDebug("shell process is not running.");
    }
}



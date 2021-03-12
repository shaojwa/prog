#include "include/searcher.h"
#include "include/config.h"

#include <QMessageBox>
#include <QDebug>
#include <QDir>
#include <QCoreApplication>
#include <iostream>
using namespace std;

Searcher::Searcher() {
    this->moveToThread(&thWorker);
    shellProc = new QProcess();
    shellProc->moveToThread(&thWorker);
    thWorker.start();
}

void Searcher::start(QString searchPath, QString pattern) {
    qDebug("searcher::start, cur_tid = %p", QThread::currentThreadId());
    QProcess::ProcessState state = shellProc->state();

    if (state != QProcess::NotRunning) {
        return;
    }

    QStringList params;
    QString shellpath = QCoreApplication::applicationDirPath();
    QString script = shellpath + "/findlog.sh";
    params << script << searchPath << pattern;
    shellProc->start("/bin/bash", params);
    if (!shellProc->waitForFinished(-1)) {
        qDebug("find log failed.");
        return;
    }
    qDebug("finished finding logs");
    QFile file(shellpath + "/" + Config::FILENAME_SHELLFIND);
    _logcount = 0;
    if (!file.exists()) {
        _logcount = -1;
        qDebug("_logcount = %d", _logcount);
        emit onFinished(_logcount);
        return;
    }

    if (!file.open(QIODevice::ReadOnly)) {
        _logcount = -1;
        qDebug("_logcount = %d", _logcount);
        emit onFinished(_logcount);
        return;
    }

    while(!file.atEnd()) {
        file.readLine();
        _logcount++;
    }
    qDebug("_logcount = %d", _logcount);
    emit onFinished(_logcount);
    return;
}

void Searcher::cancel() {
    QProcess::ProcessState state = shellProc->state();
    qDebug("searching canceled.");
    if (state == QProcess::Running) {
        shellProc->kill();
        qDebug("shell process is killed.");
    } else {
        qDebug("shell process is not running.");
    }
}



#include "include/extracter.h"
#include "include/config.h"
#include <QMessageBox>
#include <QCoreApplication>
#include <QDir>


Extracter::Extracter() {
    this->moveToThread(&thWorker);
    shellProc = new QProcess();
    shellProc->moveToThread(&thWorker);
    thWorker.start();
}


void Extracter::start() {
    qDebug("Extracter:start(), tid = %p", QThread::currentThreadId());
    QProcess::ProcessState state = shellProc->state();
    if (state != QProcess::NotRunning) {
        return;
    }

    QStringList params;
    QString shellpath = QCoreApplication::applicationDirPath();
    QString script= shellpath + "/findlog.sh";
    params << script << "-" << "-";

    shellProc->start("/bin/bash", params);

    if (!shellProc->waitForFinished(-1)) {
        emit onFinished(-1);
        return;
    } else if (0 != shellProc->exitCode()) {
        emit onFinished(-1);
        return;
    }

    QString backupPath = QDir::homePath() + "/backup";
    QDir dir(backupPath);
    if (!dir.exists()) {
        shellProc->start("mkdir", params);
    }

    QString outfile = shellpath + "/" + Config::FILENAME_SHELLFIND;
    QFile file(outfile);
    if (!file.open(QIODevice::ReadOnly)) {
        emit onFinished(-1);
        return;
    }
    QString item;
    int count = 0;
    while(!file.atEnd()) {
        item = file.readLine();
        count++;
    }

    script= shellpath + "/copylog.sh";
    params << script << backupPath;
    shellProc->start("/bin/bash", params);
    if (!shellProc->waitForFinished(-1)) {
        emit onFinished(-1);
        return;
    } else if (0 != shellProc->exitCode()) {
        emit onFinished(-1);
        return;
    }

    emit onFinished(count);
    return;
}


void Extracter::cancel() {
    QProcess::ProcessState state = shellProc->state();
    if (state == QProcess::Running) {
        shellProc->kill();
        qDebug("killed shell process.");
    } else {
        qDebug("shell process is not running.");
    }
}

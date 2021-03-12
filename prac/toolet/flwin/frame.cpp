#include "frame.h"
#include "ui_frame.h"
#include "config.h"

#include <QMessageBox>
#include <QDir>
#include <QFileDialog>
#include <qDebug>


Frame::Frame(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Frame) {
    ui->setupUi(this);

    connect(ui->pbtnSearchBrowse, SIGNAL(clicked()), this, SLOT(openFolder()));
    connect(ui->pbtnSearchStart, SIGNAL(clicked()), this, SLOT(searchStart()));
    connect(ui->pbtnSearchCancel, SIGNAL(clicked()), this, SLOT(searchCancel()));
    connect(ui->pbtnClearLogs, SIGNAL(clicked()), this, SLOT(clearLogs()));

    connect(ui->pbtnBackupBrowse, SIGNAL(clicked()), this, SLOT(openFolder()));
    connect(ui->pbtnBackupStart, SIGNAL(clicked()), this, SLOT(backupStart()));
    connect(ui->pbtnBackupCancel, SIGNAL(clicked()), this, SLOT(backupCancel()));

    ui->pbtnSearchCancel->setEnabled(false);
    ui->pbtnBackupCancel->setEnabled(false);
    ui->pbtnClearLogs->setEnabled(false);
  }

Frame::~Frame() {
    delete ui;
}


void Frame::attach(Searcher *searcher) {
    connect(this, SIGNAL(sigSearchStart(QString, QString)),
            searcher, SLOT(start(QString, QString)));

    connect(this, SIGNAL(sigSearchCancel()),
            searcher, SLOT(cancel()));

    connect(searcher, SIGNAL(sigFinished(int)),
            this, SLOT(handleSearchResult(int)));
}


void Frame::attach(Backuper *backuper) {
    connect(this, SIGNAL(sigBackupStart(QString)),
            backuper, SLOT(start(QString)));

    connect(this, SIGNAL(sigBackupCancel()),
            backuper, SLOT(cancel()));

    connect(backuper, SIGNAL(sigFinished(int)),
            this, SLOT(handleBackupResult(int)));
}


void Frame::searchStart() {
    QString path = ui->ledtSearchPath->displayText();
    if (path == QString("")) {
        QMessageBox::information(this, Config::TXT_ATTENTION,
                                 Config::TXT_NO_SEARCH_PATH);
        return ;
    }

    if (!folderExists(path)) {
        QMessageBox::information(this, Config::TXT_ATTENTION,
                                 Config::TXT_INVALID_SEARCH_PATH);
        return;
    }
    QString pattern = ui->ledtPattern->displayText();
    if (pattern == QString("")) {
        QMessageBox::information(this, Config::TXT_ATTENTION,
                                 Config::TXT_NO_PATTERN);
        return ;
    }

    qDebug() << "searchpath = "  + path  + ", pattern = " + pattern;
    emit sigSearchStart(path, pattern);

    ui->pbtnSearchStart->setEnabled(false);
    ui->pbtnSearchCancel->setEnabled(true);
}

void Frame::searchCancel() {
    emit sigSearchCancel();
    ui->pbtnSearchStart->setEnabled(true);
    ui->pbtnSearchCancel->setEnabled(false);
}


void Frame::clearLogs() {
    ui->lstLogs->clear();
    ui->pbtnClearLogs->setEnabled(false);
    ui->lblLogCount->setText("0");
}


void Frame::backupStart() {
    QString path = ui->ledtBackupPath->displayText();
    if (path == QString("")) {
        QMessageBox::information(this, Config::TXT_ATTENTION,
                                 Config::TXT_NO_BACKUP_PATH);
        return ;
    }
    if (!folderExists(path)) {
        QMessageBox::information(this, Config::TXT_ATTENTION,
                                 Config::TXT_INVALID_BACKUP_PATH);
        return;
    }

    qDebug() << "backuppath = "  + path;
    ui->pbtnBackupStart->setEnabled(false);
    ui->pbtnBackupCancel->setEnabled(true);
    ui->lblBackupInfo->setText(Config::TXT_BACKUP_INPROCESS);
    emit sigBackupStart(path);
}

void Frame::backupCancel() {
    ui->lblBackupInfo->setText(Config::TXT_BACKUP_CANCELED);
    emit sigBackupCancel();
    ui->pbtnBackupStart->setEnabled(true);
    ui->pbtnBackupCancel->setEnabled(false);
}


void Frame::openFolder() {
    QFileDialog dialog;
    dialog.setFileMode(QFileDialog::Directory);
    dialog.setOptions(QFileDialog::ShowDirsOnly);
    dialog.exec();
    QString path = dialog.selectedFiles()[0];

    QObject *obj = sender();
    QPushButton *button = qobject_cast<QPushButton *>(obj);
    if (ui->pbtnSearchBrowse == button) {
        ui->ledtSearchPath->setText(path);
    } else {
        ui->ledtBackupPath->setText(path);
    }
}


bool Frame::folderExists(QString path) {
    QDir dir(path);
    if (dir.exists()) {
        return true;
    }
    return false;
}



void Frame::handleSearchResult(int logcount) {
    qDebug("handleSearchResult");
    if (logcount == -1) {
        ui->lblSearchState->setText(Config::TXT_EXCEPTION_ON_FINDING);
    } else if (logcount == 0) {
        ui->lblSearchState->setText(Config::TXT_NO_FOUND_LOGS);
    } else {
        QString count = QString::number(logcount);
        ui->lblLogCount ->setText(count);
    }

    if (logcount > 0) {
        ui->pbtnClearLogs->setEnabled(true);
        QFile file("list.out");
        if (!file.open(QIODevice::ReadOnly)) {
            return;
        }
        QString item;
        while(!file.atEnd()) {
            item = file.readLine();
            ui->lstLogs->addItem(item);
        }
    }
    ui->pbtnSearchStart->setEnabled(true);
    ui->pbtnSearchCancel->setEnabled(false);
    return;
}

void Frame::handleBackupResult(int code) {
    qDebug("handleBackupResult");
    if (code == 0) {
        ui->lblBackupInfo->setText(Config::TXT_BACKUP_SUCCESS);
    } else {
        ui->lblBackupInfo->setText(Config::TXT_BACKUP_FAILURE);
    }
    ui->pbtnBackupStart->setEnabled(true);
    ui->pbtnBackupCancel->setEnabled(false);
    return;
}

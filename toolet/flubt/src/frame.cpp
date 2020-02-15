#include "include/frame.h"
#include "include/config.h"
#include <QMessageBox>
#include <QDir>
#include <QFileDialog>
#include <QDebug>
#include <QCoreApplication>



Frame::Frame(QWidget *parent) : QFrame(parent) {
    this->resize(Config::FrameWidth, Config::FrameHeight);
    this->setMinimumSize(Config::FrameWidth, Config::FrameHeight);
    this->setMaximumSize(Config::FrameWidth, Config::FrameHeight);
    this->setWindowFlags(Qt::FramelessWindowHint);
    this->setStyleSheet(Config::FrameStyleSheet);

    _titlebar = new TitleBar(this);
    _toolbar = new ToolBar(this);
    _panel = new PanelWin(this);
    _statebar = new StateBar(this);

    _layout = new QVBoxLayout(this);
    _layout->setSpacing(0);
    _layout->setMargin(0);
    _layout->addWidget(_titlebar);
    _layout->addWidget(_toolbar);
    _layout->addWidget(_panel);
    _layout->addWidget(_statebar);


    connect(_titlebar->_btnMin, SIGNAL(clicked()), this, SLOT(minwin()));
    connect(_titlebar->_btnClose, SIGNAL(clicked()), this, SLOT(closewin()));

    connect(_toolbar->_btnKey, SIGNAL(clicked()), _panel, SLOT(selectKey()));
    connect(_toolbar->_btnCust, SIGNAL(clicked()), _panel, SLOT(selectCust()));


    connect(_panel->_btnExtractStart, SIGNAL(clicked()), this, SLOT(extractStart()));
    connect(_panel->_btnExtractCancel, SIGNAL(clicked()), this, SLOT(extractCancel()));


    connect(_panel->_btnSearchBrowse, SIGNAL(clicked()), this, SLOT(openFolder()));
    connect(_panel->_btnSearchStart, SIGNAL(clicked()), this, SLOT(searchStart()));
    connect(_panel->_btnSearchCancel, SIGNAL(clicked()), this, SLOT(searchCancel()));
    connect(_panel->_btnClearLogs, SIGNAL(clicked()), this, SLOT(clearLogs()));

    connect(_panel->_btnBackupBrowse, SIGNAL(clicked()), this, SLOT(openFolder()));
    connect(_panel->_btnBackupStart, SIGNAL(clicked()), this, SLOT(backupStart()));
    connect(_panel->_btnBackupCancel, SIGNAL(clicked()), this, SLOT(backupCancel()));


    _panel->_btnSearchCancel->setEnabled(false);
    _panel->_btnBackupCancel->setEnabled(false);
    _panel->_btnClearLogs->setEnabled(false);

  }

Frame::~Frame() {
    delete _titlebar;
    delete _toolbar;
    delete _panel;
    delete _statebar;
}

void Frame::minwin() {
    this->setWindowState(Qt::WindowMinimized);
}

void Frame::closewin() {
    this->close();
}



void Frame::attach(Extracter *extracter) {
    connect(this, SIGNAL(onExtractStart()),
            extracter, SLOT(start()));

    connect(this, SIGNAL(onExtractCancel()),
            extracter, SLOT(cancel()));

    connect(extracter, SIGNAL(onFinished(int)),
            this, SLOT(handleExtractResult(int)));
}

void Frame::attach(Searcher *searcher) {
    connect(this, SIGNAL(onSearchStart(QString, QString)),
            searcher, SLOT(start(QString, QString)));

    connect(this, SIGNAL(onSearchCancel()),
            searcher, SLOT(cancel()));

    connect(searcher, SIGNAL(onFinished(int)),
            this, SLOT(handleSearchResult(int)));
}


void Frame::attach(Backuper *backuper) {
    connect(this, SIGNAL(onBackupStart(QString)),
            backuper, SLOT(start(QString)));

    connect(this, SIGNAL(onBackupCancel()),
            backuper, SLOT(cancel()));

    connect(backuper, SIGNAL(onFinished(int)),
            this, SLOT(handleBackupResult(int)));
}



void Frame::extractStart() {
    _panel->_lblExtractResult->setText(Config::PanelTxtExtractInprocess);
    _panel->_btnExtractStart->setEnabled(false);
    _panel->_btnExtractCancel->setEnabled(true);
    emit onExtractStart();
}


void Frame::extractCancel() {
    _panel->_lblExtractResult->setText(Config::PanelTxtExtractCanceled);
    _panel->_btnExtractStart->setEnabled(true);
    _panel->_btnExtractCancel->setEnabled(false);
    emit onExtractCancel();
}


void Frame::searchStart() {
    QString path = _panel->_ledtSearchPath->displayText();
    if (path == QString("")) {
        _panel->_lblSearchResult->setText(
                    Config::PanelTxtAttention +
                    Config::PanelTxtNoSearchPath);
        return ;
    }

    if (!folderExists(path)) {
        _panel->_lblSearchResult->setText(
                    Config::PanelTxtAttention +
                    Config::PanelTxtInvalidSearchPath);
        return;
    }
    QString pattern = _panel->_ledtPattern->displayText();
    if (pattern == QString("")) {
        _panel->_lblSearchResult->setText(
                    Config::PanelTxtAttention +
                    Config::PanelTxtNoSearchPath);
        return ;
    }
    _panel->_lblSearchResult->setText(Config::PanelTxtSearchInprocess);
    qDebug() << "searchpath = "  + path  + ", pattern = " + pattern;
    _panel->_lstLogs->clear();
    _panel->_btnSearchStart->setEnabled(false);
    _panel->_btnSearchCancel->setEnabled(true);
    emit onSearchStart(path, pattern);
}



void Frame::searchCancel() {
    _panel->_btnSearchStart->setEnabled(true);
    _panel->_btnSearchCancel->setEnabled(false);
    emit onSearchCancel();
}



void Frame::clearLogs() {
    _panel->_lstLogs->clear();
    _panel->_btnClearLogs->setEnabled(false);
    _panel->_lblSearchResult->setText("0");
}


void Frame::backupStart() {
    QString path = _panel->_ledtBackupPath->displayText();
    if (path == QString("")) {
        _panel->_lblBackupInfo->setText(
                    Config::PanelTxtAttention +
                    Config::PanelTxtNoBackupPath);
        return ;
    }
    if (!folderExists(path)) {
        _panel->_lblBackupInfo->setText(
                    Config::PanelTxtAttention +
                    Config::PanelTxtInvalidBackupPath);
        return;
    }

    qDebug() << "backuppath = "  + path;
    _panel->_btnBackupStart->setEnabled(false);
    _panel->_btnBackupCancel->setEnabled(true);
    _panel->_lblBackupInfo->setText(Config::PanelTxtBackupInprocess);
    emit onBackupStart(path);
}

void Frame::backupCancel() {
    _panel->_lblBackupInfo->setText(Config::PanelTxtBackupCanceled);
    emit onBackupCancel();
    _panel->_btnBackupStart->setEnabled(true);
    _panel->_btnBackupCancel->setEnabled(false);
}


void Frame::openFolder() {
    QFileDialog dialog;
    dialog.setFileMode(QFileDialog::Directory);
    dialog.setOptions(QFileDialog::ShowDirsOnly);
    dialog.exec();
    QString path = dialog.selectedFiles()[0];

    QObject *obj = sender();
    QPushButton *button = qobject_cast<QPushButton *>(obj);
    if (_panel->_btnSearchBrowse == button) {
        _panel->_ledtSearchPath->setText(path);
    } else {
        _panel->_ledtBackupPath->setText(path);
    }
}


bool Frame::folderExists(QString path) {
    QDir dir(path);
    if (dir.exists()) {
        return true;
    }
    return false;
}


void Frame::handleExtractResult(int logcount) {
    qDebug("handleExtractResult");
    if (logcount == -1) {
        _panel->_lblExtractResult->setText(Config::PanelTxtExceptionOnExtract);
    } else if (logcount == 0) {
        _panel->_lblExtractResult->setText(Config::PanelTxtNoExtractLogs);
    } else {
        QString count = QString::number(logcount);
        QString msg = "成功提取 " + count + " 项";
        _panel->_lblExtractResult->setText(msg);
    }
    _panel->_btnExtractStart->setEnabled(true);
    _panel->_btnExtractCancel->setEnabled(false);
    return;
}



void Frame::handleSearchResult(int logcount) {
    qDebug("handleSearchResult");
    if (logcount == -1) {
        _panel->_lblSearchResult->setText(Config::PanelTxtExceptionOnSearch);
    } else if (logcount == 0) {
        _panel->_lblSearchResult->setText(Config::PanelTxtNoFoundLogs);
    } else {
        QString count = QString::number(logcount);
        _panel->_lblSearchResult ->setText(count);
    }

    if (logcount > 0) {
        _panel->_btnClearLogs->setEnabled(true);
        QString path = QCoreApplication::applicationDirPath();
        QString outfile = path + "/" + Config::FILENAME_SHELLFIND;
        QFile file(outfile);
        if (!file.open(QIODevice::ReadOnly)) {
            return;
        }
        QString item;
        while(!file.atEnd()) {
            item = file.readLine();
            _panel->_lstLogs->addItem(item);
        }
    }
    _panel->_btnSearchStart->setEnabled(true);
    _panel->_btnSearchCancel->setEnabled(false);
    return;
}

void Frame::handleBackupResult(int code) {
    qDebug("handleBackupResult");
    if (code == 0) {
        _panel->_lblBackupInfo->setText(Config::PanelTxtBackupSuccess);
    } else {
        _panel->_lblBackupInfo->setText(Config::PanelTxtBackupFailure);
    }
    _panel->_btnBackupStart->setEnabled(true);
    _panel->_btnBackupCancel->setEnabled(false);
    return;
}

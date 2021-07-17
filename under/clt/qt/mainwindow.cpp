#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <qmessagebox.h>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pbscan_clicked()
{
    QMessageBox::information(this, "scan", "start?");
}

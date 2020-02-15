#include "include/titlebar.h"
#include "include/config.h"

#include <QMouseEvent>
#include <QFrame>

TitleBar::TitleBar(QWidget *parent):QWidget(parent)
{
    int posx = 0, posy = 0;
    int titleWidth = 0;
    this->setMinimumHeight(Config::TitleBarHeight);
    this->setMaximumHeight(Config::TitleBarHeight);
    this->setMinimumWidth(Config::FrameWidth);
    this->setMaximumWidth(Config::FrameWidth);
    this->setStyleSheet(Config::TitleBarStyleSheet);

    _lblIcon = new QLabel(this);
    _lblIcon->setPixmap(QPixmap(":/img/logopng"));
    posx = (Config::TitleBarHeight - Config::TitleIconHeight) / 2;
    posy = posx;
    _lblIcon->move(posx, posy);

    titleWidth = this->width();
    _lblTileLine = new QLabel(this);
    _lblTileLine->setText(Config::TitleLine);
    QFont &font = const_cast<QFont&>(this->font());
    font.setBold(true);
    font.setPointSize(Config::TitleBarFontSize);
    _lblTileLine->setFont(font);
    _lblTileLine->move(Config::TitleBarHeight, 10);

    _btnMin = new QPushButton(this);
    QSize minSize(Config::TitleBarMinBtnWidth,Config::TitleBarMinBtnHeight);
    _btnMin->setFixedSize(minSize);
    _btnMin->setStyleSheet(Config::TitleMinBtnStyle);

    _btnClose = new QPushButton(this);
    QSize closeSize(Config::TitleBarCloseBtnWidth,Config::TitleBarCloseBtnHeight);
    _btnClose->setFixedSize(closeSize);
    _btnClose->setStyleSheet(Config::TitleCloseBtnStyle);

    posx = titleWidth - Config::TitleBarCloseBtnWidth - Config::TitleBarButtonSpace;
    _btnClose->move(posx, 0);

    posx -= Config::TitleBarMinBtnWidth + 1;
    _btnMin->move(posx, 0);
}

void TitleBar::mousePressEvent(QMouseEvent *event) {
    if(event->button() == Qt::LeftButton) {
        _leftBtnPressed= true;
        _pressPos = event->globalPos();
    }
    event->ignore();
}

void TitleBar::mouseMoveEvent(QMouseEvent * event) {
    if (_leftBtnPressed) {
        _movePos = event->globalPos();
        QFrame *frame = qobject_cast<QFrame *>(parent());
        frame->move(frame->pos() + _movePos - _pressPos);
        _pressPos = _movePos;
    }
    event->ignore();
}

void TitleBar::mouseReleaseEvent(QMouseEvent *event){
    if (event->button() == Qt::LeftButton)
    {
        _leftBtnPressed = false;
    }
     event->ignore();
}

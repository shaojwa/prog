#include "include/statebar.h"
#include "include/config.h"

StateBar::StateBar(QWidget *parent):QWidget(parent)
{
    this->setMinimumHeight(Config::StateBarHeight);
    this->setMaximumHeight(Config::StateBarHeight);
    this->setStyleSheet(Config::StateBarStyleSheet);
    _lblStateLine = new QLabel(this);
    _lblStateLine->setText(Config::StateLine);
    _lblStateLine->setAlignment(Qt::AlignCenter);
    QFont &font = const_cast<QFont&>(this->font());
    font.setBold(true);
    font.setPointSize(Config::StateBarFontSize);
    _lblStateLine->setFont(font);
    _lblStateLine->move(10, 10);
}

#ifndef STATEBAR_H
#define STATEBAR_H

#include <QWidget>
#include <QLabel>

class StateBar:public QWidget
{
public:
    StateBar(QWidget *parent);
public:
    QLabel *_lblStateLine;
};

#endif // STATEBAR_H

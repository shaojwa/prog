#ifndef TITLEBAR_H
#define TITLEBAR_H

#include <QWidget>
#include <QLabel>
#include <QPushButton>
#include <QPoint>

class TitleBar:public QWidget
{
public:
    TitleBar(QWidget *parent);
    void mousePressEvent(QMouseEvent *event);
    void mouseMoveEvent(QMouseEvent *event);
    void mouseReleaseEvent(QMouseEvent *event);
public:
    QPushButton *_btnMin;
    QPushButton *_btnClose;
    QLabel * _lblIcon;
    QLabel * _lblTileLine;
private:
    bool _leftBtnPressed;
    QPoint _pressPos;
    QPoint _movePos;
};

#endif // TITLEBAR_H

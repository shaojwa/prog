#ifndef TOOLBUTTON_H
#define TOOLBUTTON_H

#include <QToolButton>

class ToolButton: public QToolButton
{
    Q_OBJECT

public:
    ToolButton(const QString &image, const QString &info, QWidget *parent);
};

#endif // TOOLBUTTON_H

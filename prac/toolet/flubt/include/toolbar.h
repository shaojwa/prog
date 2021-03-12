#ifndef TOOLBAR_H
#define TOOLBAR_H

#include "toolbutton.h"

class ToolBar:public QWidget
{
    Q_OBJECT
public:
    ToolBar(QWidget* parent);
    ToolButton *_btnKey;
    ToolButton *_btnCust;

 public slots:
    void selectPanel();

};

#endif // TOOLBAR_H

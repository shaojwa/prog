#include "include/config.h"
#include "include/toolbar.h"
#include "include/toolbutton.h"

ToolBar::ToolBar(QWidget *parent):QWidget(parent)
{
    this->setMinimumHeight(Config::ToolBarHeight);
    this->setMaximumHeight(Config::ToolBarHeight);
    this->setStyleSheet(Config::ToolBarStyleSheet);

    _btnKey = new ToolButton(Config::ToolBarPathKey,
                                Config::ToolBarTxtKey, this);
    _btnKey->move(Config::ToolBarButtonSpace, 0);

    _btnCust = new ToolButton(Config::ToolBarPathCust,
                                Config::ToolBarTxtCust, this);
    _btnCust->move(Config::ToolBarButtonSpace * 2 +
                 Config::ToolBarButtonWidth, 0);

    connect(_btnKey, SIGNAL(clicked()), this, SLOT(selectPanel()));
    connect(_btnCust, SIGNAL(clicked()), this, SLOT(selectPanel()));
}

void ToolBar::selectPanel() {
    ToolButton *tb = (ToolButton* )this->sender();
    if (tb == _btnKey) {
        _btnKey->setStyleSheet(Config::ToolButtonStyleSelect);
        _btnCust->setStyleSheet(Config::ToolButtonStyleNomal);
    } else {
        _btnCust->setStyleSheet(Config::ToolButtonStyleSelect);
        _btnKey->setStyleSheet(Config::ToolButtonStyleNomal);
    }
}


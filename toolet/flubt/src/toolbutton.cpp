#include "include/toolbutton.h"
#include "include/config.h"
#include <QFont>
#include <QPalette>

ToolButton::ToolButton(const QString &image, const QString &info, QWidget *parent):
    QToolButton(parent)
{
    resize(Config::ToolBarButtonWidth, Config::ToolBarButtonHeight);
    setStyleSheet(Config::ToolButtonStyleNomal);
    setToolButtonStyle(Qt::ToolButtonTextUnderIcon);
    QFont &f = const_cast<QFont &>(this->font());
    f.setBold(true);
    f.setPointSize(Config::ToolBarFontSize);

    QPalette &p = const_cast<QPalette &>(this->palette());
    p.setColor(QPalette::ButtonText, QColor(255,255,255));
    setPalette(p);
    setIconSize(QSize(Config::ToolBarIconSize, Config::ToolBarIconSize));
    setIcon(QIcon(image));
    setText(info);
}


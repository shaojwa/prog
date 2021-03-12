#include "include/config.h"
#include "include/frame.h"
#include "include/extracter.h"
#include "include/searcher.h"
#include "include/backuper.h"

#include <QApplication>
#include <QThread>
#include <QStyle>
#include <QDesktopWidget>

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    QFont font = app.font();
    app.setWindowIcon(QIcon(":/img/logoico"));
    font.setPointSize(Config::DefaultFontSize);
    app.setFont(font);
    Frame frame;
    frame.setGeometry(QStyle::alignedRect(Qt::LeftToRight, Qt::AlignCenter,
                    frame.size(),app.desktop()->availableGeometry()));
    frame.show();
    Extracter extracter;
    Searcher searcher;
    Backuper backuper;
    frame.attach(&extracter);
    frame.attach(&searcher);
    frame.attach(&backuper);
    return app.exec();
}

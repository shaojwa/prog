#include "frame.h"
#include "searcher.h"
#include "backuper.h"
#include <QApplication>
#include <QThread>

int main(int argc, char *argv[])
{
    qDebug("primary tid = %u", (uint32_t)QThread::currentThreadId());
    QApplication a(argc, argv);
    Frame frame;
    frame.show();
    Searcher searcher;
    Backuper backuper;
    frame.attach(&searcher);
    frame.attach(&backuper);
    return a.exec();
}

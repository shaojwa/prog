#ifndef SEARCHER_H
#define SEARCHER_H

#include <QThread>
#include <QProcess>

class Searcher: public QObject {
    Q_OBJECT
    QThread thWorker;
public:
    Searcher();

public slots:
    void start(QString searchPath, QString pattern);
    void cancel();

signals:
    void onFinished(int);

private:
    void parse();
    QProcess *shellProc;
    int _logcount = 0;
};

#endif // SEARCHER_H

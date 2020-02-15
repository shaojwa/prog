#ifndef EXTRACTER_H
#define EXTRACTER_H

#include <QThread>
#include <QProcess>

class Extracter: public QObject {
    Q_OBJECT
    QThread thWorker;
public:
    Extracter();

public slots:
    void start();
    void cancel();

signals:
    void onFinished(int);

private:
QProcess *shellProc;

};

#endif // EXTRACTER_H

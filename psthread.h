#ifndef PSTHREAD_H
#define PSTHREAD_H

#include <QThread>

class PSThread : public QThread
{
    Q_OBJECT

public:
    PSThread();
private:

protected:
    void run();

signals:

public slots:

};

#endif // PSTHREAD_H

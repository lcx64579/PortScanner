#include "scanner.h"
#include <QTcpSocket>
#include <QDebug>
#include <QThread>

QMutex mutexRunning;
QMutex mutexNowport;
QMutex mutexTerminate;
QMutex mutexFinish;
bool terminate;
int nowport;
bool isfinish;

Scanner::Scanner(QObject *parent) : QObject(parent)
{
    isfinish = false;
}

void Scanner::scan(QString host, int startPort, int endPort, int timeout)
{
    // qDebug()<<"Working in Thread: "<<QThread::currentThreadId();
    QTcpSocket socket;
//    emit cleanStatus();
    while(!terminate && nowport <= endPort){
        mutexTerminate.lock();
        if(terminate) break;
        mutexTerminate.unlock();

        mutexRunning.lock();
        // 在此暂停
        mutexRunning.unlock();

        mutexNowport.lock();
        int i = nowport;
        mutexNowport.unlock();

        socket.connectToHost(host, i);
        if(socket.waitForConnected(timeout))
        {
            qDebug()<<"子线程：OpenPort: "<<i;
            emit status("<开放端口> " + QString::number(i));
            socket.disconnectFromHost();
        }

        int progvalue = (int)((double)(i - startPort) / (double)(endPort - startPort) * 100);
        emit progress(progvalue);

        mutexNowport.lock();
        nowport++;
        mutexNowport.unlock();
    }

    mutexTerminate.lock();
    if(terminate){
        //emit status("<扫描终止>");
    }else{
        int intFinish = 100;
        emit progress(intFinish);
        //emit status("<扫描完成>");
    }
    mutexTerminate.unlock();

//    mutexFinish.lock();
//    if(!finish){
//        finish = true;
//        emit finished();
//    }
//    mutexFinish.unlock();
    emit finish();
}


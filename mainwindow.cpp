#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QTcpSocket>

extern QMutex mutexRunning;
extern bool terminate;
extern int nowport;
int finishCounter;
int preProgressValue;

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    paused = false;
    scanner = NULL;
    scannerThread = NULL;
}

MainWindow::~MainWindow()
{
    ui->tEdtResult->append("<正在关闭。等待当前任务完成...>");
    mutexRunning.unlock();
    terminate = true;
    for(int i = 0; i < threadNum; ++i){
        scannerThread[i].quit();
        scannerThread[i].wait();
    }
    delete ui;
}

void MainWindow::on_pBtnStartScan_clicked()
{
    QString host = ui->lEdtHost->text();
    QString strStartPort = ui->lEdtStartPort->text();
    QString strEndPort = ui->lEdtEndPort->text();
    QString strTimeout = ui->lEdtTimeout->text();
    QString strThreadNum = ui->lEdtThreadNum->text();

    // 容错性
    // ip格式验证
    QRegExp rxIP("\\d{1,3}\\.\\d{1,3}\\.\\d{1,3}\\.\\d{1,3}");
    if(!rxIP. exactMatch(host)){
        ui->tEdtResult->append("<IP格式不正确>");
        return;
    }
    // 端口号数字验证
    QRegExp rxNumber("0|[1-9]\\d{0,4}");
    if(!rxNumber.exactMatch(strStartPort) || !rxNumber.exactMatch(strEndPort)){
        ui->tEdtResult->append("<端口格式不正确>");
        return;
    }else if(strStartPort.toInt() < 0 || strStartPort.toInt() > 65535 ||
             strEndPort.toInt() < 0 || strEndPort.toInt() > 65535){
        ui->tEdtResult->append("<端口范围应当在0~65535之间>");
        return;
    }
    // 超时数字验证
    if(!rxNumber.exactMatch(strTimeout) || strTimeout.toInt() < 1){
        ui->tEdtResult->append("<超时格式不正确>");
        return;
    }
    // 线程数数字验证
    if(!rxNumber.exactMatch(strThreadNum) || strThreadNum.toInt() < 1 || strThreadNum.toInt() > 512){
        ui->tEdtResult->append("<线程数非法>");
        return;
    }

    quint16 startPort = strStartPort.toUShort();
    quint16 endPort = strEndPort.toUShort();
    quint16 timeout = strTimeout.toUShort();
    threadNum = strThreadNum.toInt();

    // 容错性
    // 端口号验证
    if(startPort > endPort){
        ui->tEdtResult->append("<起始端口号必须小于结束端口号>");
        return;
    }
    // 超时验证
    if(timeout < 1 || timeout > 10000){
        ui->tEdtResult->append("<超时必须在1ms~10000ms之间>");
        return;
    }

    // 开始扫描
    ui->pBtnStartScan->setEnabled(false);   // 禁用启动按钮

    ui->pBtnPause->setEnabled(true);        // 启用暂停按钮
    paused = false;
    ui->pBtnPause->setText("暂停扫描");
    mutexRunning.unlock();

    nowport = startPort;
    finishCounter = 0;
    terminate = false;
    preProgressValue = 0;

    scanner = new Scanner[threadNum]();
    scannerThread = new QThread[threadNum]();
    for(int i = 0; i < threadNum; ++i){
        scanner[i].moveToThread(scannerThread + i);

        // 这行注释掉可能导致内存泄漏，但目前加上会导致delete时未知原因崩溃。
//        connect(scannerThread + i, &QThread::finished, scanner + i, &QObject::deleteLater);
        connect(this, &MainWindow::startScan, scanner + i, &Scanner::scan);
        connect(scanner + i, &Scanner::status, this, &MainWindow::updateStatus);
        connect(scanner + i, &Scanner::progress, this, &MainWindow::updateProgress);
        connect(scanner + i, &Scanner::cleanStatus, this, &MainWindow::cleanStatus);
        connect(scanner + i, &Scanner::finish, this, &MainWindow::scannerFinished);

        scannerThread[i].start();
    }
    ui->tEdtResult->clear();
    emit startScan(host, startPort, endPort, timeout);      // 发送扫描开始信号
}

void MainWindow::updateStatus(const QString &text)
{
    qDebug()<<"主线程："<<text;
    ui->tEdtResult->append(text);
}

void MainWindow::updateProgress(const int &value)
{
    if(preProgressValue > value) return;
    preProgressValue = value;
    ui->pBarProgress->setValue(value);
}

void MainWindow::cleanStatus()
{
    ui->tEdtResult->clear();
}

void MainWindow::scannerFinished()
{
    terminate = true;
    finishCounter++;
    if(finishCounter == threadNum){
        for(int i = 0; i < threadNum; ++i){
            qDebug()<<"终止线程 "<<i;
            scannerThread[i].quit();
            scannerThread[i].wait();
        }
        ui->tEdtResult->append("<扫描完成>");
        ui->pBtnStartScan->setEnabled(true);    // 恢复启动按钮
        ui->pBtnPause->setEnabled(false);       // 禁用暂停按钮
    }
}

void MainWindow::on_pBtnPause_clicked()
{
    if(!paused){
        // 暂停
        qDebug()<<"locking.......";
        paused = true;
        mutexRunning.tryLock();
        ui->pBtnPause->setText("恢复扫描");
        ui->tEdtResult->append("<扫描暂停>");
    }else{
        // 恢复
        qDebug()<<"unlocking.......";
        paused = false;
        mutexRunning.unlock();
        ui->pBtnPause->setText("暂停扫描");
        ui->tEdtResult->append("<扫描恢复>");
    }
}

void MainWindow::on_pBtnExit_clicked()
{
    ui->tEdtResult->append("<正在关闭。等待当前任务完成...>");
    mutexRunning.unlock();
    terminate = true;
    for(int i = 0; i < threadNum; ++i){
        scannerThread[i].quit();
        scannerThread[i].wait();
    }
    emit close();
}

#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "scanner.h"
#include <QThread>
#include <QMutex>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_pBtnStartScan_clicked();
    void on_pBtnPause_clicked();
    void on_pBtnExit_clicked();

public slots:
    void updateStatus(const QString &text); // 更新状态信息
    void updateProgress(const int &value);  // 更新进度条
    void cleanStatus();     // 清屏
    void scannerFinished();     // 扫描结束后处理

private:
    Ui::MainWindow *ui;
    QThread *scannerThread;
    Scanner *scanner;
    bool paused;
    int threadNum;

signals:
    void startScan(QString host, int startPort, int endPort, int timeout);      // 扫描开始信号

};

#endif // MAINWINDOW_H

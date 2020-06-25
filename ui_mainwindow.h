/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.9.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QProgressBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QGridLayout *gridLayout_2;
    QGridLayout *gridLayout;
    QTextEdit *tEdtResult;
    QProgressBar *pBarProgress;
    QLineEdit *lEdtHost;
    QLabel *label;
    QLabel *label_4;
    QPushButton *pBtnExit;
    QLineEdit *lEdtEndPort;
    QLabel *label_3;
    QLabel *label_2;
    QLineEdit *lEdtStartPort;
    QPushButton *pBtnPause;
    QLabel *label_5;
    QPushButton *pBtnStartScan;
    QLineEdit *lEdtTimeout;
    QLabel *label_6;
    QLineEdit *lEdtThreadNum;
    QStatusBar *statusBar;
    QToolBar *mainToolBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(480, 638);
        QFont font;
        font.setFamily(QString::fromUtf8("\350\220\215\346\226\271-\347\256\200"));
        MainWindow->setFont(font);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        gridLayout_2 = new QGridLayout(centralWidget);
        gridLayout_2->setSpacing(6);
        gridLayout_2->setContentsMargins(11, 11, 11, 11);
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        gridLayout = new QGridLayout();
        gridLayout->setSpacing(6);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        tEdtResult = new QTextEdit(centralWidget);
        tEdtResult->setObjectName(QStringLiteral("tEdtResult"));
        tEdtResult->setReadOnly(true);

        gridLayout->addWidget(tEdtResult, 8, 0, 1, 4);

        pBarProgress = new QProgressBar(centralWidget);
        pBarProgress->setObjectName(QStringLiteral("pBarProgress"));
        pBarProgress->setValue(0);

        gridLayout->addWidget(pBarProgress, 4, 0, 1, 4);

        lEdtHost = new QLineEdit(centralWidget);
        lEdtHost->setObjectName(QStringLiteral("lEdtHost"));
        lEdtHost->setAutoFillBackground(false);
        lEdtHost->setMaxLength(15);

        gridLayout->addWidget(lEdtHost, 0, 1, 1, 3);

        label = new QLabel(centralWidget);
        label->setObjectName(QStringLiteral("label"));

        gridLayout->addWidget(label, 0, 0, 1, 1);

        label_4 = new QLabel(centralWidget);
        label_4->setObjectName(QStringLiteral("label_4"));

        gridLayout->addWidget(label_4, 7, 0, 1, 1);

        pBtnExit = new QPushButton(centralWidget);
        pBtnExit->setObjectName(QStringLiteral("pBtnExit"));

        gridLayout->addWidget(pBtnExit, 9, 3, 1, 1);

        lEdtEndPort = new QLineEdit(centralWidget);
        lEdtEndPort->setObjectName(QStringLiteral("lEdtEndPort"));
        lEdtEndPort->setMaxLength(5);

        gridLayout->addWidget(lEdtEndPort, 1, 3, 1, 1);

        label_3 = new QLabel(centralWidget);
        label_3->setObjectName(QStringLiteral("label_3"));

        gridLayout->addWidget(label_3, 1, 2, 1, 1);

        label_2 = new QLabel(centralWidget);
        label_2->setObjectName(QStringLiteral("label_2"));

        gridLayout->addWidget(label_2, 1, 0, 1, 1);

        lEdtStartPort = new QLineEdit(centralWidget);
        lEdtStartPort->setObjectName(QStringLiteral("lEdtStartPort"));
        lEdtStartPort->setMaxLength(5);

        gridLayout->addWidget(lEdtStartPort, 1, 1, 1, 1);

        pBtnPause = new QPushButton(centralWidget);
        pBtnPause->setObjectName(QStringLiteral("pBtnPause"));
        pBtnPause->setEnabled(false);

        gridLayout->addWidget(pBtnPause, 7, 3, 1, 1);

        label_5 = new QLabel(centralWidget);
        label_5->setObjectName(QStringLiteral("label_5"));

        gridLayout->addWidget(label_5, 2, 0, 1, 1);

        pBtnStartScan = new QPushButton(centralWidget);
        pBtnStartScan->setObjectName(QStringLiteral("pBtnStartScan"));
        pBtnStartScan->setAutoDefault(true);

        gridLayout->addWidget(pBtnStartScan, 3, 3, 1, 1);

        lEdtTimeout = new QLineEdit(centralWidget);
        lEdtTimeout->setObjectName(QStringLiteral("lEdtTimeout"));
        lEdtTimeout->setMaxLength(6);

        gridLayout->addWidget(lEdtTimeout, 2, 1, 1, 1);

        label_6 = new QLabel(centralWidget);
        label_6->setObjectName(QStringLiteral("label_6"));

        gridLayout->addWidget(label_6, 2, 2, 1, 1);

        lEdtThreadNum = new QLineEdit(centralWidget);
        lEdtThreadNum->setObjectName(QStringLiteral("lEdtThreadNum"));
        lEdtThreadNum->setMaxLength(4);

        gridLayout->addWidget(lEdtThreadNum, 2, 3, 1, 1);


        gridLayout_2->addLayout(gridLayout, 0, 0, 1, 1);

        MainWindow->setCentralWidget(centralWidget);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MainWindow->setStatusBar(statusBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        mainToolBar->setMovable(false);
        mainToolBar->setFloatable(false);
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        QWidget::setTabOrder(lEdtHost, lEdtStartPort);
        QWidget::setTabOrder(lEdtStartPort, lEdtEndPort);
        QWidget::setTabOrder(lEdtEndPort, lEdtTimeout);
        QWidget::setTabOrder(lEdtTimeout, lEdtThreadNum);
        QWidget::setTabOrder(lEdtThreadNum, pBtnStartScan);
        QWidget::setTabOrder(pBtnStartScan, pBtnPause);
        QWidget::setTabOrder(pBtnPause, tEdtResult);
        QWidget::setTabOrder(tEdtResult, pBtnExit);

        retranslateUi(MainWindow);

        pBtnStartScan->setDefault(true);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "\347\253\257\345\217\243\346\211\253\346\217\217\345\231\250", Q_NULLPTR));
        lEdtHost->setPlaceholderText(QApplication::translate("MainWindow", "127.0.0.1", Q_NULLPTR));
        label->setText(QApplication::translate("MainWindow", "IP\345\234\260\345\235\200", Q_NULLPTR));
        label_4->setText(QApplication::translate("MainWindow", "\346\211\253\346\217\217\347\273\223\346\236\234", Q_NULLPTR));
        pBtnExit->setText(QApplication::translate("MainWindow", "\351\200\200\345\207\272", Q_NULLPTR));
        lEdtEndPort->setInputMask(QString());
        lEdtEndPort->setText(QString());
        lEdtEndPort->setPlaceholderText(QApplication::translate("MainWindow", "550", Q_NULLPTR));
        label_3->setText(QApplication::translate("MainWindow", "\347\273\223\346\235\237\347\253\257\345\217\243", Q_NULLPTR));
        label_2->setText(QApplication::translate("MainWindow", "\345\274\200\345\247\213\347\253\257\345\217\243", Q_NULLPTR));
        lEdtStartPort->setInputMask(QString());
        lEdtStartPort->setText(QString());
        lEdtStartPort->setPlaceholderText(QApplication::translate("MainWindow", "1", Q_NULLPTR));
        pBtnPause->setText(QApplication::translate("MainWindow", "\346\232\202\345\201\234\346\211\253\346\217\217", Q_NULLPTR));
        label_5->setText(QApplication::translate("MainWindow", "\350\266\205\346\227\266(ms)", Q_NULLPTR));
        pBtnStartScan->setText(QApplication::translate("MainWindow", "\345\274\200\345\247\213\346\211\253\346\217\217", Q_NULLPTR));
        lEdtTimeout->setInputMask(QString());
        lEdtTimeout->setText(QString());
        lEdtTimeout->setPlaceholderText(QApplication::translate("MainWindow", "50", Q_NULLPTR));
        label_6->setText(QApplication::translate("MainWindow", "\347\272\277\347\250\213\346\225\260", Q_NULLPTR));
        lEdtThreadNum->setPlaceholderText(QApplication::translate("MainWindow", "256", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H

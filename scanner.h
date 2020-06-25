#ifndef SCANNER_H
#define SCANNER_H

#include <QObject>
#include <QMutex>

class Scanner : public QObject
{
    Q_OBJECT
public:
    explicit Scanner(QObject *parent = nullptr);

signals:
    void progress(const int &value);
    void status(const QString &text);
    void cleanStatus();
    void finish();

public slots:
    void scan(QString host, int startPort, int endPort, int timeout);

};

#endif // SCANNER_H

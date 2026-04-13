#ifndef TEST_H
#define TEST_H

#include <QObject>
#include <QDebug>
#include <QTimer>

class Test : public QObject
{
    Q_OBJECT
    QTimer m_timer;

public:
    explicit Test(QObject *parent = nullptr);
    int counter;

public slots:
    void timeout();

signals:
};

#endif // TEST_H

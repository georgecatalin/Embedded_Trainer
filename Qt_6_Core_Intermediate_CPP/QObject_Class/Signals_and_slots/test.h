#ifndef TEST_H
#define TEST_H

#include <QObject>
#include <QDebug>

class Test : public QObject
{
    Q_OBJECT
public:
    explicit Test(QObject *parent = nullptr);
    virtual ~Test();
    void activate();

signals:
    //always public, always defined and not implemented
    void alarm(QString message);

public slots:
    //can be public, private or protected, always defined and implemented
    //can be executed like a standalone function
    void wake(QString message);
};

#endif // TEST_H

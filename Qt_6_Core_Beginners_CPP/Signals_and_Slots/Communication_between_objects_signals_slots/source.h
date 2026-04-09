#ifndef SOURCE_H
#define SOURCE_H

#include <QObject>
#include <QDebug>

class Source : public QObject
{
    Q_OBJECT
public:
    explicit Source(QObject *parent = nullptr);
    void Function_1();

signals:
    void mySignal(QString message_to_send);
};

#endif // SOURCE_H

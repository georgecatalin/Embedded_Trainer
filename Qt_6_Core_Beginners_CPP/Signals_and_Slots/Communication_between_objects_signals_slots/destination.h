#ifndef DESTINATION_H
#define DESTINATION_H

#include <QObject>
#include <QDebug>

class Destination : public QObject
{
    Q_OBJECT
public:
    explicit Destination(QObject *parent = nullptr);

public slots:
    void mySlot(QString message_to_receive);

signals:
};

#endif // DESTINATION_H

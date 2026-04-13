#ifndef STATION_H
#define STATION_H

#include <QObject>
#include <QDebug>

class Station : public QObject
{
    Q_OBJECT
public:
    explicit Station(QObject *parent = nullptr, int channel = 0, QString name = "anonymous");
   void broadcast(QString message);

    int channel;
    QString name;

signals:
    void send(int channel, QString name, QString message);

public slots:


};

#endif // STATION_H

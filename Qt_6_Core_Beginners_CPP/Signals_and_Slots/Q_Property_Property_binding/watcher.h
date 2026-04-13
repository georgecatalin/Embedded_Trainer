#ifndef WATCHER_H
#define WATCHER_H

#include <QObject>
#include <QDebug>

class Watcher : public QObject
{
    Q_OBJECT
public:
    explicit Watcher(QObject *parent = nullptr);

public slots:
    void messageChanged(QString message);

signals:
};

#endif // WATCHER_H

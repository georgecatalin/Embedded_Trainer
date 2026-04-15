#ifndef CAT_H
#define CAT_H

#include <QObject>
#include <QDebug>

class Cat : public QObject
{
    Q_OBJECT
public:
    explicit Cat(QObject *parent = nullptr);

public slots:
    void run();

signals:
    void miaow();
};

#endif // CAT_H

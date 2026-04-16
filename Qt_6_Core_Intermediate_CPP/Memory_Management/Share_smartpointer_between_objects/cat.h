#ifndef CAT_H
#define CAT_H

#include <QObject>
#include <QDebug>
#include <QSharedPointer>
#include "toy.h"

class Cat : public QObject
{
    Q_OBJECT
public:
    explicit Cat(QObject *parent = nullptr,QString name ="");
    virtual ~Cat();

    void play(QSharedPointer<Toy> toy);

private:
    QSharedPointer<Toy> m_toy;
signals:
};

#endif // CAT_H

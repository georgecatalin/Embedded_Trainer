#ifndef CANINE_H
#define CANINE_H

#include <QObject>
#include "animal.h"

class Canine : public Animal
{
    Q_OBJECT
public:
    explicit Canine(QObject *parent = nullptr);
    void bark();

signals:
};

#endif // CANINE_H

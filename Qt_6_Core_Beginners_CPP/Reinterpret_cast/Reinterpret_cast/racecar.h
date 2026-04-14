#ifndef RACECAR_H
#define RACECAR_H

#include "car.h"
#include <QObject>
#include <QDebug>

class Racecar : public Car
{
    Q_OBJECT
public:
    explicit Racecar(QObject *parent = nullptr);
    int power;
    void race();

signals:
};

#endif // RACECAR_H

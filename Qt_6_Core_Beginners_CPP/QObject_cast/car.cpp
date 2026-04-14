#include "car.h"

Car::Car(QObject *parent)
    : QObject{parent}
{}

void Car::start()
{
    qInfo()<<this<<"starts ";
}

void Car::stop()
{
    qInfo()<<this<<"stops ";
}

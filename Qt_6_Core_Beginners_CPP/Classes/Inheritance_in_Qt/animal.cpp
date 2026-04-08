#include "animal.h"

Animal::Animal(QObject *parent) : QObject{parent}
{
    qInfo() << "An object of the class Animal is created ->"<<this;
}

void Animal::isAlive()
{
    qInfo()<<"True";
}

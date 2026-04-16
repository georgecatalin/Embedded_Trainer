#include "toy.h"
#include <qdebug.h>

Toy::Toy(QObject *parent,QString name) : QObject{parent}
{
    setObjectName(name);
    qInfo()<<"Constructor for object ->"<<this;
}

Toy::~Toy()
{
    qInfo()<<"Deconstructor for object ->"<<this;
}

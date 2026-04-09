#include "animal.h"

Animal::Animal(QObject *parent) : QObject{parent}
{
    qInfo()<<this<<" Animal object constructed.";
}

Animal::~Animal()
{
    qInfo()<<this<<" Animal object deconstructed.";
}

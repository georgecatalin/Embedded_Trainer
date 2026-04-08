#include "lion.h"

Lion::Lion(QObject *parent)
{
    qInfo()<<this<<" constructed .";
}

void Lion::speak()
{
    qInfo()<<"Roar!!!!!";
    //this way we can appeal to the speak() method from the base class, through scope resolution operator
    Feline::speak();
}
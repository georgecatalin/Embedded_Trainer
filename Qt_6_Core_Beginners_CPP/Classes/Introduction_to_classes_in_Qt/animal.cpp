#include "animal.h"

Animal::Animal(QObject *parent)
    : QObject{parent}
{
    qInfo()<< this;
}

void Animal::speak(QString voice)
{
    qInfo()<<this<< " speaks like "<< voice;
}

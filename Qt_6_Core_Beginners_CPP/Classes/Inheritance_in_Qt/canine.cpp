#include "canine.h"

Canine::Canine(QObject *parent): Animal(parent)
{
    qInfo() << "An object of type Canine created ->"<< this;
}


void Canine::bark()
{
    qInfo()<<"Ham ham";
}
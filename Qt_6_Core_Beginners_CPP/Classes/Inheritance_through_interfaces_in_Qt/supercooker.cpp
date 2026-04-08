#include "supercooker.h"

Supercooker::Supercooker(QObject *parent) : QObject{parent}
{
    qInfo()<<"An object of type Supercooker was created ->"<<this;
}


bool Supercooker::Cook()
{
    return true;
}

bool Supercooker::freeze()
{
    return true;
}

bool Supercooker::toast()
{
    return true;
}
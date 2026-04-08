#include "feline.h"
#include <qdebug.h>

Feline::Feline(QObject *parent) : QObject(parent)
{
    qInfo()<<this<<" constructed.";
}

void Feline::speak()
{
    qInfo() << "Miaow!!!";
}

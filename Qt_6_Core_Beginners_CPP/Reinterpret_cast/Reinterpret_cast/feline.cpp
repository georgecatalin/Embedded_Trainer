#include "feline.h"

Feline::Feline(QObject *parent)
    : QObject{parent}
{}

void Feline::miaow()
{
    qInfo()<<this<< " miaows";
}

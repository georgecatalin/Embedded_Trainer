#include "cat.h"

Cat::Cat(QObject *parent)
    : QObject{parent}
{}

void Cat::run()
{
    qInfo()<<"Cat runs because of ->"<<sender();
    emit miaow();
}

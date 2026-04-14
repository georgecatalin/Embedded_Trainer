#include "racecar.h"

Racecar::Racecar(QObject *parent)
    : Car{parent}
{}

void Racecar::race()
{
    qInfo()<<this<<" races fast.";
}

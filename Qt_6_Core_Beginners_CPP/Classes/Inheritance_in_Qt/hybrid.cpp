#include "hybrid.h"

Hybrid::Hybrid(QObject *parent) : Canine(parent)
{
    qInfo()<<"An object of type Hybrid was created ->"<<this;

}
void Hybrid::attacks()
{
    qInfo()<< "The hybrid attacks.";
}
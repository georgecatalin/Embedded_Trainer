#include "feline.h"

Feline::Feline(QObject *parent)
{
    qInfo()<< "An object of type Feline was created ->"<< this;
}

void Feline::miaows()
{
    qInfo()<< "Miaow";
}
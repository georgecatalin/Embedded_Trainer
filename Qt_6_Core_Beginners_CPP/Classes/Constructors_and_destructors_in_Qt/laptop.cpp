#include "laptop.h"

Laptop::Laptop(QObject *parent, QString name) : QObject{parent}
{
    name = name;
    qInfo()<< this << " with the name -> "<<name;

}

Laptop::~Laptop()
{
    qInfo() << "I am in the destructor of -> " << this;
}

float Laptop::convertWeightToKg()
{
    return weight * 0.45;
}

void Laptop::test()
{
    qInfo()<< "Test: object ("<< this <<") with name "<< name;
}

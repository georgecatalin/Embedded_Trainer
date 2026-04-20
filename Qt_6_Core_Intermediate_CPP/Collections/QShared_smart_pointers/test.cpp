#include "test.h"

Test::Test(QObject *parent,QString name) : QObject{parent}
{
    this->setObjectName(name);
    qInfo()<<"Fired the constructor for the object "<<this;
}


Test::~Test()
{
     qInfo()<<"Fired the destructor for the object "<<this;
}

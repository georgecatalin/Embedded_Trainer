#include "test.h"

Test::Test(QObject *parent,QString name)
    : QObject{parent}
{
    setObjectName(name);
    qInfo()<<"Constructor for object "<<this;
}

Test::~Test()
{
    qInfo()<<"Destructor for object "<<this;
}

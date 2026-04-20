#include "test.h"

Test::Test(QObject *parent,QString name) : QObject{parent}
{
    setObjectName(name);
    qInfo()<<"Fired constructor for the object "<<this;
}

Test::~Test()
{
  qInfo()<<"Fired destructor for the object "<<this;
}

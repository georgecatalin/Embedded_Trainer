#include "test.h"
#include <typeinfo.h>

Test::Test(QObject *parent) : QObject(parent)
{
    qInfo()<<"a new object of type "<<typeid(*this).name()<< " was created -> "<<this; //print the type with C++


    //Print the type with Qt
    qInfo()<<"a new object of type "<<this->metaObject()->className()<<" was created -> "<<this;
}

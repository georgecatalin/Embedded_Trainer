#include "test.h"

Test::Test(QObject *parent) : QObject{parent}
{
    qInfo()<<this<<" Test object constructed";
}

Test::~Test()
{
    qInfo()<<this<<" Test object deconstructed";
}

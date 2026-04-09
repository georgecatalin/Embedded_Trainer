#include "test.h"

Test::Test(QObject *parent) : QObject{parent}
{
    qInfo()<<this<<" constructed.";
}

Test::~Test()
{
    qInfo()<<this<< " deconstructed.";
}

void Test::doStuff()
{
    qInfo()<<this<< Q_FUNC_INFO;
}

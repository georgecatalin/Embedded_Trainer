#include "source.h"

Source::Source(QObject *parent) : QObject{parent}
{
    qInfo()<<this<<" Source object constructed.";
}

void Source::Function_1()
{
    qInfo()<<"emitting the signal from Source now";
    emit mySignal("Hello from function 1");
}

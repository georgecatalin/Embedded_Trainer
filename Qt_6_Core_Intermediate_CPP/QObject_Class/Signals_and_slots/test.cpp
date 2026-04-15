#include "test.h"
#include <QCoreApplication>

Test::Test(QObject *parent) : QObject(parent)
{
    qInfo()<<"Constructor for the object ->"<<this;
}

Test::~Test()
{
    qInfo()<<"Deconstructor for the object ->"<<this;
}

void Test::activate()
{
    QString message = "HELP!!";
    emit alarm(message);

}

void Test::wake(QString message)
{
    qInfo()<<"Received from"<<sender()<<" the message ->"<<message;
    QCoreApplication::quit();

}

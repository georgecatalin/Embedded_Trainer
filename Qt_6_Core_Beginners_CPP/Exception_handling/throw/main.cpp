#include <QCoreApplication>
#include <QDebug>
#include <iostream>

bool divide()
{
    int max = 1978;
    int divisor = 0;
    qInfo()<<"Enter your divisor:";
    std::cin>>divisor;

    if(divisor == 1) return false;

    if(divisor == 0)
    {
        qInfo()<<"Divisor is 00";
        throw "can not divide with 0";
    }

    int result = max/divisor;
    qInfo()<<"Result is="<<result;

    return true;
}

int main(int argc, char *argv[])
{
     QCoreApplication a(argc, argv);

    do
     {

    } while(divide());

    return QCoreApplication::exec();
}

#include <QCoreApplication>
#include <QDebug>
#include <iostream>

using namespace std;


bool doDivision(int max)
{
    try
    {
        int divisor = 0;
        qInfo()<<"Enter the divisor=";
        cin>>divisor;

        if(divisor == 0) throw std::invalid_argument("Can not divide by 0");
        if(divisor > 5) throw std::out_of_range("divisor out of range");

        int result = max/divisor;
        qInfo()<<"The result is="<<result;
        return true;
    }
    catch(std::exception &e)
    {
        qWarning()<<"There occurred an error ->"<<e.what();
        return false;
    }
}

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    int max = 14;
    do
    {

    }while(doDivision(max));


    return QCoreApplication::exec();
}

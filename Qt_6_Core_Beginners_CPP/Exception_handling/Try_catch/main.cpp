#include <QCoreApplication>
#include <QDebug>
#include <iostream>


bool divide(int max)
{
    try
    {
        int divisor = 0;
        qInfo()<<" Enter the divisor=";

        std::cin>>divisor;

        if(divisor == 0) throw QString("Unable to divide to 0");
        if(divisor == 1) throw 99;
        if(divisor > 5) throw std::runtime_error("Divisor greater than 5");

        int result = max/divisor;
        qInfo()<<"The result is ="<<result;

    }
    catch(QString e)
    {
        qWarning()<<" Division by zero was caught ->"<<e;
        return false;
    }
    catch(int e)
    {
        qWarning()<<" Division to 1 was caught ->"<<e;
        return false;
    }
    catch(std::runtime_error e)
    {
        qWarning()<<" Divisor to more than 5 ->"<<e.what();
        return false;
    }
    catch (...) //catch all
    {
        qWarning()<<" This catches all";
        return false;
    }



    return true;
}

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    int max  = 47;

    do
    {

    }while(divide(max));

    return QCoreApplication::exec();
}

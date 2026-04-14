#include <QCoreApplication>
#include <QDebug>
#include <iostream>

using namespace std;

struct myIssue: public exception
{
    const char *description;
    const char *what() const throw()
    {
        return "My issue is";
    }
};

bool doDivision(int max)
{
    try
    {
        int divisor = 0;
        qInfo()<<"Enter the divisor=";
        cin>>divisor;

        if(divisor == 0)
        {
            myIssue myissue;
            myissue.description = "some error occurred";
            throw myissue;
        }


        int result = max/divisor;
        qInfo()<<"The result is="<<result;
        return true;
    }
    catch (myIssue &e)
    {
        qWarning()<<"Error -> "<<e.what()<<" described through "<<e.description;
        return false;
    }
}

int main(int argc, char *argv[])
{
    int max = 48;

    do
    {

    }while(doDivision(max));

    return QCoreApplication::exec();
}

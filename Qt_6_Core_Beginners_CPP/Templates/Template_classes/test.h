#ifndef TEST_H
#define TEST_H

#include <QDebug>

template<class T>
class Test
{
private:
public:
    Test()
    {
        qInfo()<<"no argument constructor called for object ->"<<this<<" : ";
    };
    T add(T value1, T value2)
    {
        return value1 + value2;
    }

    void display(T value)
    {
        qInfo()<<value;
    }
};



#endif // TEST_H


//Notes: in Qt , all the classes that inherit from QObject can not be templated.
//the implementation of functions for templated classes has to be done in the .h file
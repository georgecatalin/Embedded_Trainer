#include <QCoreApplication>
#include <QDebug>
#include "test.h"


template<class T>
void function_display(T value)
{
    qInfo()<<value;
}


int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    Test<int> myTestInt;
    qInfo()<< myTestInt.add(1,3);
    myTestInt.display(2);

    Test<double> myTestDouble;
    qInfo()<<myTestDouble.add(3.14,1.2);
    myTestDouble.display(3.4);

    Test<QString> myTestQString;
    qInfo()<<myTestQString.add(QString("Mara"),QString("Calin"));

    Test<QObject *> myTestObject;
    QObject obj;
    myTestObject.display(&obj); //in order to use templates with QObject type objects, use a reference for the object cast to its pointer type


    //use a QObject with a templated function
    function_display<int>(1);

    QObject object1;
    function_display<QObject *>(&object1);

    return QCoreApplication::exec();
}

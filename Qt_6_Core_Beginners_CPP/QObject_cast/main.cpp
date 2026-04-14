#include <QCoreApplication>
#include "car.h"
#include "racecar.h"
#include "feline.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

   //QObject_cast is a specific type of cast which works well in Qt because much of the created classes inherit from the QObject class
   //QObject_cast is provided via the Q_OBJECT macro

    Racecar *racecar = new Racecar(&a);
    racecar->start();
    racecar->stop();
    racecar->race();


    //upcast from derived class to base class
    Car *car = qobject_cast<Car *>(racecar);
    car->start();
    car->stop();

    //downcast from base clas to derived class
    Racecar *racecar_back = qobject_cast<Racecar *>(car);
    racecar_back->start();
    racecar_back->stop();
    racecar_back->race();

    //pitfall: qobject_cast does not work with non-Qt classes, that is classes that do not inherit from QObject
    Feline *feline = qobject_cast<Feline *>(racecar);
    feline->miaow(); // QObject(0x0)  miaows  feline = 0x0 that is null object
    //feline->start();

    return QCoreApplication::exec();
}

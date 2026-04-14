#include <QCoreApplication>
#include "car.h"
#include "racecar.h"
#include "feline.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    Car *car = new Car(&a);
    car->start();
    car->stop();


    //explicit conversion (unsafe because we are not certain about its outcome)
    Racecar *car1 = (Racecar *) car;
    car1->start();
    car1->stop();
    //car1->race(); //error on runtime

    //dynamic and static conversion only apply to pointers and references

    Racecar *racecar = new Racecar(&a);
    racecar->start();
    racecar->stop();
    racecar->race();

    //dynamic cast
    Racecar *racecar1 = dynamic_cast<Racecar *>(car1);

    //dynamic cast happens at runtime, one can verify and validate the conversion before usage for avoiding crash of the pp
    if(racecar1)
    {
        racecar1->start();
        racecar1->stop();
        racecar1->race();
    }

    //static cast happens at compile time. the same object , residing at the same memory location is taken otherwise
    //one can not control the outcome of the conversion it takes from granted it should work
    Racecar *racecar2 = static_cast<Racecar *>(car1);
    racecar2->start();
    racecar2->stop();
    racecar2->race();



    return QCoreApplication::exec();
}

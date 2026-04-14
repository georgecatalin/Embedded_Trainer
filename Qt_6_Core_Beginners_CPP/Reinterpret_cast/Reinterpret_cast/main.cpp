#include <QCoreApplication>
#include "car.h"
#include "racecar.h"
#include "feline.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    Racecar *racecar = new Racecar(&a);
    racecar->start();
    racecar->stop();
    racecar->race();


    //polymorphic cast with dynamic_cast
    Car *car = dynamic_cast<Car *>(racecar);
    if(car)
    {
        car->start();
        car->stop();
    }

    //non-polymorphic cast (change the existing memory location)
    Racecar *racecar1 = static_cast<Racecar *>(car);
    racecar1->start();
    racecar1->stop();
    racecar1->race(); //works

    qInfo()<<"reinterpret cast";

    //reinterpret cast, the C way to reinterpreting what is at that location (dangerous cause it might mean data loss)
    int *pointer = reinterpret_cast<int *>(racecar1);
    Car *car2 = reinterpret_cast<Car *>(pointer);

    car2->start();
    car2->stop();


    return QCoreApplication::exec();
}

/*
 * 1. static_cast (The Disciplined Choice)

This is your "go-to" cast. It performs conversions that are well-defined by the C++ language rules. The compiler checks if the conversion makes sense at compile-time.

    Numeric Conversions: Converting float to int (truncation).

    Pointer Navigation: Converting a pointer of a derived class to its base class (upcasting).

    Void Pointers: Converting a void* back to a typed pointer.


2. reinterpret_cast (The Dangerous Choice)

This is the "trust me, I know what I'm doing" cast. It tells the compiler to take the bit pattern of one expression and treat it as if it were a completely different type, without changing the bits at all.

    Low-Level Work: Converting a pointer to an integer (to look at a specific memory address).

    Incompatible Pointers: Converting a Car* to a Fruit*. The compiler won't stop you, even though it makes no sense.

    Hardware/Drivers: Reading raw bytes from a buffer or a hardware register.
 *
 *

 *
 * */



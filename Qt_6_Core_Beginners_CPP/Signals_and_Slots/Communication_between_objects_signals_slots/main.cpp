#include <QCoreApplication>
#include "source.h"
#include "destination.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    Source sourceObject;
    Destination destinationObject;

    QObject::connect(&sourceObject,&Source::mySignal,&destinationObject,&Destination::mySlot);

    sourceObject.Function_1(); //a manner to start communication signal slot from the source

    destinationObject.mySlot("Now the slot is appealed as a function in the destination");


    /*
     * destinationObject.mySlot("Now the slot is appealed as a function in the destination"); is simply a normal, direct C++ method call.

     In Qt, a slot is still just a member function (with some extra Qt “meta-object” information so it can be invoked through the signal/slot system).
     That means you can call it in two different ways:

    Direct call
        destinationObject.mySlot("Now the slot is appealed as a function in the destination");

          * This immediately executes Destination::mySlot(...) right there in main().
          * It does not involve Source, mySignal, or the connection at all.
          * It behaves like any other function call: same thread, immediate execution, return when finished.

    Signal-driven call (what the connection enables)
        QObject::connect(&sourceObject, &Source::mySignal, &destinationObject, &Destination::mySlot);
        sourceObject.Function_1();  // presumably emits mySignal(...)
     *
     */

    return QCoreApplication::exec();
}

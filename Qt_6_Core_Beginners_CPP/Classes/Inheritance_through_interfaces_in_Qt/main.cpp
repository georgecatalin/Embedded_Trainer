#include <QCoreApplication>
#include "Freezer.h"
#include "Microwave.h"
#include "Toaster.h"
#include "supercooker.h"


int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    Supercooker supercooker;

    //use the functions which were implemented via the interfaces
    qInfo()<<supercooker.Cook();
    qInfo()<<supercooker.freeze();
    qInfo()<<supercooker.toast();


    return QCoreApplication::exec();
}

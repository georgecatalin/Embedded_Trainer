#include <QCoreApplication>
#include "feline.h"
#include "lion.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    Feline feline;
    feline.speak();

    qInfo()<<"------";

    Lion lion;
    lion.speak(); //Lion::speak();

    lion.Feline::speak(); //override the method from Lion

    return QCoreApplication::exec();
}

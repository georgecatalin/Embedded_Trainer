#include <QCoreApplication>
#include "laptop.h"

void test_laptop(Laptop& laptop)
{
    laptop.test();
}

void make_laptop()
{
    Laptop mine(nullptr,"DELL");
    Laptop yours(nullptr,"LENOVO");

    mine.weight = 3;
    yours.weight = 4;

    test_laptop(mine);
    test_laptop(yours);

}



int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    make_laptop();

    return QCoreApplication::exec();
}

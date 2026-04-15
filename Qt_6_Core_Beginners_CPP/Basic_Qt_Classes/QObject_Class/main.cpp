#include <QCoreApplication>
#include <QDebug>
#include "cat.h"
#include "dog.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    Dog dog;
    dog.setObjectName("Zizan");

    Cat cat;
    cat.setObjectName("Zorro");

    QObject::connect(&cat,&Cat::miaow,&dog,&Dog::chase);
    QObject::connect(&dog,&Dog::bark,&cat,&Cat::run);

    emit dog.bark();

    return QCoreApplication::exec();
}

/*
Cat runs because of -> Dog(0x624cbff730, name = "Zizan")
Dog is chasing -> Cat(0x624cbff720, name = "Zorro")
*/
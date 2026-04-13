#include <QCoreApplication>
#include "owner.h"
#include "dog.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    Owner owner;
    Dog dog;

    QObject::connect(&owner,&Owner::treats,&dog,&Dog::treats); //Qt-Auto connection

    for (int i = 0; i < 10; ++i)
    {
        //If the connection type between signal and slot is unspecified ,
       //then it is take by default as AUTO. A slot will be generated multiple times for a given signal
       // even if the signal was emitted only once
        //QObject::connect(&owner,&Owner::treats,&dog,&Dog::treats);

        /*
         * Owner gives snack.
          Dog receives treats.
          Dog receives treats.
          Dog receives treats.
          Dog receives treats.
          Dog receives treats.
          Dog receives treats.
          Dog receives treats.
          Dog receives treats.
          Dog receives treats.
          Dog receives treats.
          Dog receives treats.
         */


        //changing the connection type to unique, then there will be a single slot for a signal emitted
         QObject::connect(&owner,&Owner::treats,&dog,&Dog::treats, Qt::UniqueConnection);

         /*
          *
          * Owner gives snack.
            Dog receives treats.
        */
    }

    owner.giveSnack();

    return QCoreApplication::exec();
}

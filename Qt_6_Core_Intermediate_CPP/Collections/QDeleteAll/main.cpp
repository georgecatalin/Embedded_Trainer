#include <QCoreApplication>
#include <QDebug.h>
#include "test.h"




int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    QList<Test *> list;

    //fill in the list
    for(int i=0;i<10;i++)
    {
        list.append(new Test(nullptr,"object"+QString::number(i)));
    }

    //display the list
    qInfo()<<list;

    //delete all the pointer members from the list
    qDeleteAll(list);

    //although the elements in the list do not point anywhere (dangling pointers) the list exists
     qInfo()<<list.count();

    //delete also the list
     list.clear();

    //display the elements in the list
    for(int i=0;i<10;i++)
    {
        //qInfo()<<list[i]; //will crash the app
    }



    return QCoreApplication::exec();
}

#include <QCoreApplication>
#include <QSharedPointer>
#include <QMap>
#include "test.h"


typedef QMap<QString,QSharedPointer<Test>> TypeMap;

void testMapAuto(void)
{
    TypeMap map;

    qInfo()<<"Fill in the QMap object";

    for(int i=0;i<8;i++)
    {
         QString id = "id-"+QString::number(i);
         QString name = "name-"+QString::number(i);
         QSharedPointer<Test> ptr(new Test(nullptr,name));

         map.insert(id,ptr);
    }

    qInfo()<<"preview the elements of the QMap object";
    foreach (QString key, map.keys())
    {
        qInfo()<<key<<" -- "<<map[key].data();
    }

    qInfo()<<"clear the QMap object and the smart pointers lose their scope, hence, delete automatically";
    map.clear();
}

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    testMapAuto();

    return QCoreApplication::exec();
}

/*
Fill in the QMap object
Fired the constructor for the object  Test(0x19636bd8f30, name = "name-0")
Fired the constructor for the object  Test(0x19636bd91f0, name = "name-1")
Fired the constructor for the object  Test(0x19636bd8ff0, name = "name-2")
Fired the constructor for the object  Test(0x19636bd8ef0, name = "name-3")
Fired the constructor for the object  Test(0x19636bd8fd0, name = "name-4")
Fired the constructor for the object  Test(0x19636bd9130, name = "name-5")
Fired the constructor for the object  Test(0x19636bd9190, name = "name-6")
Fired the constructor for the object  Test(0x19636bd90f0, name = "name-7")
preview the elements of the QMap object
"id-0"  --  Test(0x19636bd8f30, name = "name-0")
"id-1"  --  Test(0x19636bd91f0, name = "name-1")
"id-2"  --  Test(0x19636bd8ff0, name = "name-2")
"id-3"  --  Test(0x19636bd8ef0, name = "name-3")
"id-4"  --  Test(0x19636bd8fd0, name = "name-4")
"id-5"  --  Test(0x19636bd9130, name = "name-5")
"id-6"  --  Test(0x19636bd9190, name = "name-6")
"id-7"  --  Test(0x19636bd90f0, name = "name-7")
clear the QMap object and the smart pointers lose their scope, hence, delete automatically
Fired the destructor for the object  Test(0x19636bd90f0, name = "name-7")
Fired the destructor for the object  Test(0x19636bd9190, name = "name-6")
Fired the destructor for the object  Test(0x19636bd9130, name = "name-5")
Fired the destructor for the object  Test(0x19636bd8fd0, name = "name-4")
Fired the destructor for the object  Test(0x19636bd8ef0, name = "name-3")
Fired the destructor for the object  Test(0x19636bd8ff0, name = "name-2")
Fired the destructor for the object  Test(0x19636bd91f0, name = "name-1")
Fired the destructor for the object  Test(0x19636bd8f30, name = "name-0")
*/

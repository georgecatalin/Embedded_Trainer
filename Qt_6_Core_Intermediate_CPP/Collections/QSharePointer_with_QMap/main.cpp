#include <QCoreApplication>
#include <QDebug>
#include "test.h"


void testMapDelete(void)
{
    QMap<QString,Test *> myMap;

    //fill in the map object
    qInfo()<<"fill in the map object";
    for (int i = 0; i < 6; ++i)
    {
        QString id = "id_"+QString::number(i);
        QString name = "name_"+QString::number(i);
        myMap.insert(id,new Test(nullptr,name));
    }

    //preview the elements of the map
    qInfo()<<"preview the elements of the map";
    foreach (QString key, myMap.keys())
    {
        qInfo()<<key<<" -- "<<myMap[key];
    }

    qInfo()<<"delete where the pointers of the QMap are pointing to";
    qDeleteAll(myMap);
    //After this step, the QMap collection still contains pointers, but they are pointed to memory addresses which were deleted, therefore they are dangling pointers
    qInfo()<<"Deleting the collection itself, the QMap object";
    myMap.clear();



}

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    testMapDelete();

    return QCoreApplication::exec();
}

/*
fill in the map object
Fired constructor for the object  Test(0x1f9892490f0, name = "name_0")
Fired constructor for the object  Test(0x1f989249230, name = "name_1")
Fired constructor for the object  Test(0x1f989249110, name = "name_2")
Fired constructor for the object  Test(0x1f989249090, name = "name_3")
Fired constructor for the object  Test(0x1f989248ef0, name = "name_4")
Fired constructor for the object  Test(0x1f989248f10, name = "name_5")
preview the elements of the map
"id_0"  --  Test(0x1f9892490f0, name = "name_0")
"id_1"  --  Test(0x1f989249230, name = "name_1")
"id_2"  --  Test(0x1f989249110, name = "name_2")
"id_3"  --  Test(0x1f989249090, name = "name_3")
"id_4"  --  Test(0x1f989248ef0, name = "name_4")
"id_5"  --  Test(0x1f989248f10, name = "name_5")
delete where the pointers of the QMap are pointing to
Fired destructor for the object  Test(0x1f9892490f0, name = "name_0")
Fired destructor for the object  Test(0x1f989249230, name = "name_1")
Fired destructor for the object  Test(0x1f989249110, name = "name_2")
Fired destructor for the object  Test(0x1f989249090, name = "name_3")
Fired destructor for the object  Test(0x1f989248ef0, name = "name_4")
Fired destructor for the object  Test(0x1f989248f10, name = "name_5")
Deleting the collection itself, the QMap object
*/

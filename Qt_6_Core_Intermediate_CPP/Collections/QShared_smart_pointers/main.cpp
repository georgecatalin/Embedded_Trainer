#include <QCoreApplication>
#include "test.h"
#include <QSharedPointer>

void testListAuto(void)
{
    QList<QSharedPointer<Test>> list;

    for(int i =0;i<6; i++)
    {
        QSharedPointer<Test> smart_pointer(new Test(nullptr,"SmartPointer"+QString::number(i)));
        list.append(smart_pointer);
    }

    qInfo()<<"Preview the pointers";

    foreach (QSharedPointer<Test> var, list)
    {
        qInfo()<<var.data();
    }


    qInfo()<<"Delete pointer[0]";

    list.removeAt(0);

    qInfo()<<"Clear the list out.";
    list.clear();
}

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    testListAuto();

    return QCoreApplication::exec();
}


/*
11:17:32: Starting D:\Workshop\LearningStuffs\Embedded_Trainer\Qt_6_Core_Intermediate_CPP\Collections\QShared_smart_pointers\build\Desktop_Qt_6_11_0_MinGW_64_bit-Debug\QShared_smart_pointers.exe...
Fired the constructor for the object  Test(0x21d62b76c60, name = "SmartPointer0")
Fired the constructor for the object  Test(0x21d62b77670, name = "SmartPointer1")
Fired the constructor for the object  Test(0x21d62b77530, name = "SmartPointer2")
Fired the constructor for the object  Test(0x21d62b773f0, name = "SmartPointer3")
Fired the constructor for the object  Test(0x21d62b77470, name = "SmartPointer4")
Fired the constructor for the object  Test(0x21d62b77570, name = "SmartPointer5")
Preview the pointers
Test(0x21d62b76c60, name = "SmartPointer0")
Test(0x21d62b77670, name = "SmartPointer1")
Test(0x21d62b77530, name = "SmartPointer2")
Test(0x21d62b773f0, name = "SmartPointer3")
Test(0x21d62b77470, name = "SmartPointer4")
Test(0x21d62b77570, name = "SmartPointer5")
Delete pointer[0]
Fired the destructor for the object  Test(0x21d62b76c60, name = "SmartPointer0")
Clear the list out.
Fired the destructor for the object  Test(0x21d62b77670, name = "SmartPointer1")
Fired the destructor for the object  Test(0x21d62b77530, name = "SmartPointer2")
Fired the destructor for the object  Test(0x21d62b773f0, name = "SmartPointer3")
Fired the destructor for the object  Test(0x21d62b77470, name = "SmartPointer4")
Fired the destructor for the object  Test(0x21d62b77570, name = "SmartPointer5")
*/
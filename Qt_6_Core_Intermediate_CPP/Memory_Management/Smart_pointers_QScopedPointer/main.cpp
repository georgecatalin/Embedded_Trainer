#include <QCoreApplication>
#include <QDebug>
#include "test.h"
#include <QScopedPointer>


void testFunc()
{
    QScopedPointer<Test> smartPointer(new Test());
    smartPointer->setObjectName("Some name");

    qInfo()<<"Pointer on the stack->"<<&smartPointer;
    qInfo()<<"Pointer data->"<<smartPointer.data();
    qInfo()<<"The object name"<<smartPointer->objectName();

}

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    testFunc();

    return QCoreApplication::exec();
}

/*
Constructor for object  Test(0x1a0e2f76bd0)
Pointer on the stack-> 0x707e3ffd08
Pointer data-> Test(0x1a0e2f76bd0, name = "Some name")
The object name "Some name"
Destructor for object  Test(0x1a0e2f76bd0, name = "Some name")
*/
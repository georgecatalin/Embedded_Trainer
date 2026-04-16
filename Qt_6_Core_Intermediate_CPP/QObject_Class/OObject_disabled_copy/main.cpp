#include <QCoreApplication>
#include <QDebug>


void testPointer(QObject *ptr)
{
    qInfo()<<ptr;
}

void testReference(QObject &obj)
{
    qInfo()<<&obj;
}

void testCopy(QObject obj)
{
    qInfo()<<&obj;
}

/*
QObjects derived objects can not be copied because it would mess with the Signal and Slots implementation.
Which signal to which slot
*/

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    QObject person;
    person.setObjectName("George");

    testPointer(&person);
    testReference(person);

    //testCopy(person);  //error

    return QCoreApplication::exec();
}

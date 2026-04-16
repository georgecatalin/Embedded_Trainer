#include <QCoreApplication>
#include <QDebug>
#include <QSharedPointer>
#include "test.h"

QSharedPointer<Test> getPointer()
{

    QSharedPointer<Test> smartPointer(new Test(nullptr,"Test0"));

    qInfo()<<"The pointer data is :"<<smartPointer.data();
    qInfo()<<"The pointer address on the stack is:"<<&smartPointer;
    qInfo()<<"The pointer name is:"<<smartPointer->objectName();

    return smartPointer;

}

void doWork(QSharedPointer<Test> ptr)
{
    qInfo()<<"Working with a copy of the pointer, reference counter adds one up each call";
    qInfo()<<"The pointer data is :"<<ptr.data();
    qInfo()<<"The pointer address on the stack is:"<<&ptr;
    qInfo()<<"The pointer name is:"<<ptr->objectName();
}

void testMe()
{
    QSharedPointer<Test> sp = getPointer();
    doWork(sp);

    qInfo()<<&sp;

    qInfo()<<"I am done now. Reference counter will go down to 0 and the smart pointer will be automatically destructed.";
}

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    testMe();

    return QCoreApplication::exec();
}

/*
 NOTES
--------
Difference between QScopedPointer<T> and QSharedPointer<T>

- In Qt, both QScopedPointer and QSharedPointer are designed to prevent memory leaks by ensuring that an object is deleted when it is no longer needed.
- The difference lies entirely in ownership.

1. QScopedPointer: The "Sole Owner"

    QScopedPointer is the Qt equivalent of std::unique_ptr. It says: "I own this object, and no one else can have it."

Lifetime: The object is deleted as soon as the QScopedPointer goes out of scope (e.g., the function ends).
Transferability: You cannot copy it. This prevents two pointers from trying to delete the same memory.
Performance: Extremely fast. It has zero overhead compared to a raw pointer.

 void createLocalReport()
{
    // The 'Report' object is deleted automatically at the '}'
    QScopedPointer<Report> report(new Report());
    report->generate();

    // QScopedPointer<Report> other = report; // ERROR! Cannot copy.
}

2. QSharedPointer: The "Community Member"

SharedPointer is the Qt equivalent of std::shared_ptr. It uses Reference Counting.


Lifetime: The object is deleted only when the last QSharedPointer pointing to it is destroyed.
Transferability: You can copy it as much as you like. Every time you copy it, an internal counter goes up. When a pointer is destroyed, the counter goes down.
 Performance: Slightly slower than QScopedPointer because it must manage the reference counter (which is thread-safe/atomic).

 */

/*
Constructor for object -> Test(0x208a9446bd0, name = "Test0")
The pointer data is : Test(0x208a9446bd0, name = "Test0")
The pointer address on the stack is: 0x31c59ff8c0
The pointer name is: "Test0"
Working with a copy of the pointer, reference counter adds one up each call
The pointer data is : Test(0x208a9446bd0, name = "Test0")
The pointer address on the stack is: 0x31c59ff8d0
The pointer name is: "Test0"
0x31c59ff8c0
I am done now. Reference counter will go down to 0 and the smart pointer will be automatically destructed.
Deconstructor for object -> Test(0x208a9446bd0, name = "Test0")
*/

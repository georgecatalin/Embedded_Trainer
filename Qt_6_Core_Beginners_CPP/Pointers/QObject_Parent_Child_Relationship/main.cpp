#include <QCoreApplication>
#include "animal.h"
#include "test.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    Test *ptrTest = new Test(&a); // 'a' is the parent object of ptrTest object. once 'a' is out of scope, ptrTest is automatically deleted
    ptrTest->ptrAnimal = new Animal(ptrTest); //'ptrTest' is the parent of ptrAnimal. Once 'ptrTest' is deleted, 'ptrAnimal' is deleted as well.

    delete ptrTest; //After deleting ptrTest, ptrAnimal is deleted too because it is its child in the object tree


    return QCoreApplication::exec();
    //object 'a' goes out of scope. hence any child of his, as part of the object tree created by Qt is being deleted automatically
}

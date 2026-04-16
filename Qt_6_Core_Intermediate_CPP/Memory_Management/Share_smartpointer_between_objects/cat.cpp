#include "cat.h"

Cat::Cat(QObject *parent, QString name) : QObject{parent}
{
    setObjectName(name);
    qInfo()<<"Constructor for object ->"<<this;
}

Cat::~Cat()
{
    qInfo()<<"Deconstructor for object ->"<<this;
}

void Cat::play(QSharedPointer<Toy> toy)
{

    /*
QSharedPointer<Toy> toy: The cat receives a shared pointer to a toy. The reference count increases because the function now "holds" a reference to that toy.
        m_toy.swap(toy): This is a clever way to handle assignment.

        m_toy (presumably a member variable of the Cat) takes the new toy.

        The toy parameter (the local variable) takes whatever toy the Cat was holding before.

        When the function ends, the old toy (now in the local toy variable) is released.

toy.data(): This returns the "raw" pointer address of the toy.
*/


    m_toy.swap(toy);
    qInfo()<<"Playing with the object ->"<<toy.data();
}

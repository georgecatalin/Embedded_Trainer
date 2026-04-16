#include <QCoreApplication>
#include <QDebug>
#include <QSharedPointer>
#include <vector>
#include "cat.h"
#include "toy.h"

void test()
{
    int max = 10;
    std::vector<QSharedPointer<Cat>> cats(max); //creating a "shelf" with 10 slots. Each slot is designed to hold a QSharedPointer to a Cat

    QSharedPointer<Toy> toy(new Toy()); //create one toy. Because it is a QSharedPointer, it keeps track of how many "owners" it has. Right now, the Reference Count is 1.

    for(int i=0;i<max;i++)
    {
        //cats[i].reset(new Cat()); //deletes whatever as in cats[i] (nothing) and points to cat actually QSharedPointer::reset()

        //or better since there is nothing in cats[i]
        cats[i]=QSharedPointer<Cat>::create(new Cat());
        cats[i]->play(toy); //by the end of the loop toy will be assigned to 10 separate cats, and the reference counter of the toy will be 10
    }

    qInfo()<<"play is completed.";

    //The Cats die first: Since the cats vector is destroyed, all 10 QSharedPointer<Cat> objects are destroyed. This triggers the Cat destructors (~Cat).
    //As each Cat is destroyed, its internal m_toy shared pointer is also destroyed.
    //The Toy's reference count drops: 10, 9, 8...
    // When the very last cat dies (and the local toy variable is gone), the count hits 0.
    //Only then is the Toy object automatically deleted from memory.

    /*
    test() ends. The local toy pointer is destroyed. Count = 10.

    Vector starts destroying cats[0]. cats[0]'s internal m_toy is destroyed. Count = 9.
    Vector destroys cats[1]. cats[1]'s internal m_toy is destroyed. Count = 8.

    ...this continues until...
    Vector destroys cats[9]. cats[9]'s internal m_toy is destroyed. Count = 0.
    BOOM: The QSharedPointer destructor sees the 0, and it finally calls delete toy;.
    */
}



int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    test();
    return QCoreApplication::exec();
}

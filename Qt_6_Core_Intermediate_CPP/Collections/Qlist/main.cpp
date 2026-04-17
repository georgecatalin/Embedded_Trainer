#include <QCoreApplication>
#include <QList>
#include <QDebug>

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    QList<int> myList;

    for (int i = 0; i < 10; ++i)
    {
        myList.append(i);
    }

    qInfo()<<myList;


    qInfo()<<"Length:"<<myList.length();
    qInfo()<<"Size:"<<myList.size();
    qInfo()<<"Count:"<<myList.count();


    qInfo()<<"Count how many times 2 in list:"<<myList.count(2);

    myList<<1978<<1977<<2011;

    qInfo()<<myList;

    myList.remove(1);
    qInfo()<<myList;

    /*
    QList<T> QList::sliced(qsizetype index, qsizetype n) const
        index: The starting position (where the cut begins).
        n: The number of elements to take (the length of the new list).
    */

    QList<int> newList = myList.sliced(2,5);
    qInfo()<<newList; //QList(0, 2, 6, 7, 8, 9, 1978, 1977, 2011)

    int indexOf = myList.indexOf(2011);
    qInfo()<<indexOf;

    bool is2011in = myList.contains(2011);
    qInfo()<<is2011in;

    return QCoreApplication::exec();
}

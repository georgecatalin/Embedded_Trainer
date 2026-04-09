#include <QCoreApplication>
#include <QDebug>

void printCpy(QObject copy)
{
    //qInfo()<<copy<<Q_FUNC_INFO; //QObject can not be copied, this will be shown as erroneous in the IDE
}

void printPtr(QObject *ptr)
{
    qInfo()<<ptr<<Q_FUNC_INFO;
}

QObject *getPtr()
{
    QObject *a_ptr_on_the_heap = new QObject();
    return a_ptr_on_the_heap; // mind that memory must be managed in the callee, otherwise a memory leak will occur
}


int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    QObject *ptr = getPtr();
    qInfo()<<ptr;

    printPtr(ptr);

    delete ptr;

    return QCoreApplication::exec();
}

#include <QCoreApplication>
#include "test.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    Test test;

    //all the member variables and member functions from the QObject Class which are public can be access via test object
    //test.whatever();

    return QCoreApplication::exec();
}

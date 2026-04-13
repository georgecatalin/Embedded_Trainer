#include <QCoreApplication>
#include <QDebug>
#include "test.h"
#include "watcher.h"
#include <QVariant>

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    Test test;
    Watcher watcher;

    QObject::connect(&test,&Test::messageChanged,&watcher,&Watcher::messageChanged);

    test.setMessage("setting via function setter");
    test.setProperty("messageProperty",QVariant("setting via Property"));

    return QCoreApplication::exec();
}

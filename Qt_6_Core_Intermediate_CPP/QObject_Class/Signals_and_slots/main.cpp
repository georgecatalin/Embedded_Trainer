#include <QCoreApplication>
#include "test.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    Test mom;
    Test child;

    mom.setObjectName("Mom");
    child.setObjectName("Child");

    qInfo()<<&mom;
    qInfo()<<&child;

    QObject::connect(&mom,&Test::alarm,&child,&Test::wake,Qt::AutoConnection);

    mom.activate();

    return 0;
}

/*
QCoreApplication::exec() enters the event loop and blocks until someone calls QCoreApplication::quit() / QCoreApplication::exit()
(or the app is otherwise terminated). Since nothing in the code you showed quits the app, it keeps running, so stack unwinding never happens and the local objects mom
and child are never destroyed—therefore you don’t see ~Test() output.
*/
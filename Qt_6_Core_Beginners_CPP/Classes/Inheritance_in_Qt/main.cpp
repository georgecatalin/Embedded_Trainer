#include <QCoreApplication>
#include "hybrid.h"
#include "feline.h"
#include "canine.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    // Set up code that uses the Qt event loop here.
    // Call QCoreApplication::quit() or QCoreApplication::exit() to quit the application.
    // A not very useful example would be including
    // #include <QTimer>
    // near the top of the file and calling
    // QTimer::singleShot(5000, &a, &QCoreApplication::quit);
    // which quits the application after 5 seconds.

    // If you do not need a running Qt event loop, remove the call
    // to QCoreApplication::exec() or use the Non-Qt Plain C++ Application template.

    Canine Zizou;
    Zizou.bark();
    Zizou.isAlive();

    Feline Pisung;
    Pisung.miaows();
    Pisung.isAlive();

    // Hybrid Coco;
    // Coco.bark();
    // Coco.miaows();
    // Coco.Canine::isAlive();
    // Coco.attacks();

    return QCoreApplication::exec();
}

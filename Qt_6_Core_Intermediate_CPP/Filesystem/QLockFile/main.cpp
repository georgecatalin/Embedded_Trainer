#include <QCoreApplication>
#include <QDebug>
#include <QLockFile>
#include <QDir>

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    QString lockPath = QDir::temp().absoluteFilePath("templock.txt");

    qInfo()<<"Trying to acquire lock...";


    QLockFile lock(lockPath);

    if(!lock.tryLock(100))
    {
        qDebug()<<"Another instance of the application is already running...";
        return 1;
    }

    qInfo()<<"The application was started properly";

    lock.unlock();

    qInfo()<<"This instance of the application was closed...";

    return a.exec();
}

#include <QCoreApplication>
#include <QDebug>

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    qint8 value8 = 0;
    qint16 value16 = 0;
    qint32 value32 = 0;
    qint64 value64 = 0;
    qintptr valueptr = 0;

    qInfo()<<"qint8 "<<sizeof(value8);
    qInfo()<<"qint16 "<<sizeof(value16);
    qInfo()<<"qint32 "<<sizeof(value32);
    qInfo()<<"qint64 "<<sizeof(value64);
    qInfo()<<"qintptr "<<sizeof(valueptr);

 //irrespective of the operating system destination, the size of the variables will be consistent

    return QCoreApplication::exec();
}

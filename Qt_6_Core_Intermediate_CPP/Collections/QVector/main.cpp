#include <QCoreApplication>
#include <QVector>
#include <QDebug>

//in the newer versions of Qt, after Qt 6.x , QVector is an alias for QList

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    QVector<int> myVector;
    myVector<<1977<<1978<<2011;
    qInfo()<<myVector;  //QList(1977, 1978, 2011)


    return QCoreApplication::exec();
}

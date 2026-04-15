#include <QCoreApplication>
#include <QDebug>
#include <QVariant>

void test(QVariant value)
{
    qInfo()<<value;

    int i = 0;
    bool conversionOk = false;

    i = value.toInt(&conversionOk);

    if(conversionOk)
    {
        qInfo()<<"Conversion was ok ->"<<i;
    }
    else
    {
        qInfo()<<value<<" is not an int";
    }
}

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    //QVariant is a wrapper around multiple data types in Qt. It is used heavily with QML

    int i = 1977;
    QString name("Mara");

    test(i);
    test(name);


    return QCoreApplication::exec();
}

/*
    QVariant(int, 1977)
    Conversion was ok -> 1977
    QVariant(QString, "Mara")
    QVariant(QString, "Mara")  is not an int
*/

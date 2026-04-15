#include <QCoreApplication>
#include <QDebug>

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    QString name = "George Calin";
    QByteArray buffer = name.toUtf8();

    qInfo()<<name;
    qInfo()<<buffer;

    qInfo()<<buffer.append("!");
    qInfo()<<buffer.at(1);

    QString nameback(buffer);
    qInfo()<<nameback;

    //basic encoding and decoding
    qInfo()<<buffer.toBase64();
    qInfo()<<buffer.toHex();

    return QCoreApplication::exec();
}

/*
"George Calin"
    "George Calin"
    "George Calin!"
    e
    "George Calin!"
    "R2VvcmdlIENhbGluIQ=="
    "47656f7267652043616c696e21"
*/
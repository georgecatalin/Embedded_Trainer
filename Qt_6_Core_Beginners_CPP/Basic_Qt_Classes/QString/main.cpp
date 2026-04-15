#include <QCoreApplication>
#include <QDebug>

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    QString fullName = "George Calin";

    qInfo()<<fullName;
    qInfo()<<fullName.mid(1,3); //'eor'
    qInfo()<<fullName.insert(0,"Mr. ");
    qInfo()<<fullName.split(" ");

    int indexfound = fullName.indexOf("rge",0); // new string where search will be done is 'Mr. George Calin'
    qInfo()<<indexfound;

    if(indexfound > -1)
    {
        qInfo()<<fullName.remove(0,indexfound);
    }

    return QCoreApplication::exec();
}

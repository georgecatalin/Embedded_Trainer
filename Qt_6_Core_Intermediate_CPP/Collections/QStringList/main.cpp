#include <QCoreApplication>
#include <QDebug>
#include <QStringList>

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    QStringList myList{"George"};

    myList<<"Mara"<<"Zizou";
    qInfo()<<myList;

    myList.append("Vali");
    qInfo()<<myList;

    QString concatenated = myList.join(",");
    qInfo()<<concatenated;

    qInfo()<<"George is in the list?"<<myList.contains("George");
    qInfo()<<"Index of Mara in the list?"<<myList.indexOf("Mara");
    qInfo()<<"Read position in List:"<<myList.at(myList.indexOf("Zizou"));

    qInfo()<<myList.replaceInStrings("a","@");

    return QCoreApplication::exec();
}

/*
QList("George", "Mara", "Zizou")
QList("George", "Mara", "Zizou", "Vali")
"George,Mara,Zizou,Vali"
George is in the list? true
Index of Mara in the list? 1
Read position in List: "Zizou"
QList("George", "M@r@", "Zizou", "V@li")
*/

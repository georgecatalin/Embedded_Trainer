#include <QCoreApplication>
#include <QDebug>
#include <QMap>

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    QMap<QString, int> myMap;

    myMap.insert("George",47);
    myMap.insert("Mara",14);
    myMap.insert("Sorina",48);
    qInfo()<<myMap;

    foreach (QString key, myMap.keys())
    {
        qInfo()<<key<<" = "<<myMap[key];
    }

    myMap["Zizou"] = 6;

    qInfo()<<"Zizou is in map?"<<myMap.contains("Zizou");

    qInfo()<<myMap.keys();
    qInfo()<<myMap.values();


    qInfo()<<"Zizan in the map is="<<myMap.value("Zizan",-1);//it displays -1 cause Zizan is not found in the map

    return QCoreApplication::exec();
}

/*
QMap(("George", 47)("Mara", 14)("Sorina", 48))
    "George"  =  47
    "Mara"  =  14
    "Sorina"  =  48
    Zizou is in map? true
      QList("George", "Mara", "Sorina", "Zizou")
      QList(47, 14, 48, 6)
      Zizan in the map is= -1
*/
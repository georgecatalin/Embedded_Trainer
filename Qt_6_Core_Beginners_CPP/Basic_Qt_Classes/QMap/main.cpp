#include <QCoreApplication>
#include <QDebug>
#include "pet.h"

typedef QMap<QString,Pet *> petList;

petList createListOfPets(int max)
{
    petList map;
    for (int i = 0; i < max; ++i)
    {
        QString id = QString::number(i);
        Pet *pet = new Pet();
        pet->setAge(i*2);
        pet->setName("Pet: " + id);
        map.insert(id,pet);
    }

    return map;
}

void listMap(petList map)
{
    foreach (QString key, map.keys())
    {
        Pet *pet = map.value(key);
        qInfo()<<key<<"Age:"<<pet->age()<<" Name:"<<pet->name();
    }
}

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    petList myMap = createListOfPets(10);
    listMap(myMap);
    qInfo()<<myMap.count();

    //Add a new element to the map manually
    Pet *pet = new Pet();
    pet->setAge(3);
    pet->setName("Coco");
    myMap.insert("special",pet);

    listMap(myMap);
     qInfo()<<myMap.count();


    //Add a new element to the map manually - keys are unique
    Pet *pet1 = new Pet();
    pet1->setAge(23);
    pet1->setName("Coco");
    myMap.insert("2",pet1);

    listMap(myMap);
     qInfo()<<myMap.count();


     qDeleteAll(myMap.values()); //delete all pointers in the list, list remains with dangling pointers
     myMap.clear();

    return QCoreApplication::exec();
}

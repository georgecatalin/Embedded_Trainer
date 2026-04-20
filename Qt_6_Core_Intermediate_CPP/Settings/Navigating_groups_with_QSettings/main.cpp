#include <QCoreApplication>
#include <QDebug>
#include <QSettings>
#include <QVariant>
#include <QRandomGenerator>

void setAge(QSettings *settings, QString group, QString name, int age)
{
    settings->beginGroup(group);
    settings->setValue(name,QVariant(age));
    settings->endGroup();
}

int getAge(QSettings *settings, QString group, QString name)
{
    settings->beginGroup(group);
    //verify if the name exists
    if(!settings->contains(name))
    {
        qWarning()<<"The key '"<<name<<"' does not exist in group '"<<group<<"'";
        settings->endGroup();
        return 0;
    }

    //get the value
    bool conversionResult;
    int age=settings->value(name).toInt(&conversionResult);
    settings->endGroup();

    if(!conversionResult)
    {
        qWarning()<<"I could not convert the value '"<<settings->value(name);
        settings->endGroup();
        return 0;
    }

    return age;
}

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    QCoreApplication::setOrganizationName("Freelancer");
    QCoreApplication::setOrganizationDomain("georgecalin.ro");
    QCoreApplication::setApplicationName("Groups");

    QSettings settings(QCoreApplication::organizationName(),QCoreApplication::applicationName());
    setAge(&settings,"parents","George", 47);
    setAge(&settings,"parents","Sorina",48);

    setAge(&settings,"children","Biggerah",14);
    setAge(&settings,"children","Zizoulack",6);

    QStringList otherPeople;
    otherPeople<<"Sandu"<<"Vali"<<"Petrina"<<"Mitica";

    foreach(QString people, otherPeople)
    {
        int age = QRandomGenerator::global()->bounded(100);
        setAge(&settings,"test",people,age);
    }

    settings.sync();
    qInfo()<<"File name is:"<<settings.fileName();

    //preview the elements by navigating child groups in settings
    for(QString group : settings.childGroups())
    {
        settings.beginGroup(group);

        qInfo()<<"Group:"<<group;

        for(QString key:settings.childKeys())
        {
            qInfo()<<"Key:"<<key<<" has value '"<<settings.value(key).toString();
        }

        settings.endGroup();
    }


    return QCoreApplication::exec();
}

/*
File name is: "\\HKEY_CURRENT_USER\\Software\\Freelancer\\Groups"
Group: "children"
    Key: "Biggerah"  has value ' "14"
   Key: "Zizoulack"  has value ' "6"
Group: "parents"
     Key: "George"  has value ' "47"
    Key: "Sorina"  has value ' "48"
Group: "test"                                                                                                                                                                                     Key: "Mitica"  has value ' "61"
    Key: "Petrina"  has value ' "87"
    Key: "Sandu"  has value ' "32"
    Key: "Vali"  has value ' "76"
*/

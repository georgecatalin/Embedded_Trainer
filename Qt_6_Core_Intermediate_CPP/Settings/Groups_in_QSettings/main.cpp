#include <QCoreApplication>
#include <QDebug>
#include <QSettings>
#include <QVariant>

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
        qWarning()<<"I could not convert the value '"<<settings->value(name)<<"' to int";
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

    int ageGeorge = getAge(&settings,"parents","George");
    int ageBiggerah =getAge(&settings,"children","Biggerah");

    qInfo()<<"Age of George"<<ageGeorge;
    qInfo()<<"Age of Biggerah"<<ageBiggerah;


    return QCoreApplication::exec();
}

/*
Age of George 47
Age of Biggerah 14
*/

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

    QString filename = a.applicationDirPath() +"/settings.ini";
    qInfo()<<"The path is going to be ->"<<filename;


    QSettings settings(filename,QSettings::Format::IniFormat);

    settings.beginGroup("people");
    settings.setValue("George",47);
    settings.setValue("Mara",14);
    settings.endGroup();

    settings.sync(); //saves the settings to persistent memory HDD or SSD whatever

    //save separately, using the utility function will enter the group on its own
    setAge(&settings,"people","Bibberah",14);

    //read data
    settings.beginGroup("people");

    qInfo()<<"George:"<<settings.value("George").toString();
    qInfo()<<"Bibberah:"<<settings.value("Bibberah",QVariant("Bibberah does not exist in this group of settings."));
    qInfo()<<"Mara:"<<settings.value("Mara",QVariant("Mara does not exist in this group"));
    qInfo()<<"Zizou:"<<settings.value("Zizou",QVariant("Zizou does not exist in this group"));


    settings.endGroup();

    return 0;
}
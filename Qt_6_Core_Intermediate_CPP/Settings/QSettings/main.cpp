#include <QCoreApplication>
#include <QDebug>
#include <QSettings>
#include <QVariant>

void info(QSettings &settings) //QSettings does not inherit QObject hence it can be copied as a non-reference parameter that is void info(QSettings settings)
{
    qInfo()<<settings.fileName();
    qInfo()<<settings.allKeys(); //the settings are saved in a dictionary like/map like collection and should be accessed by their keys
}

void save(QSettings &settings)
{
    settings.setValue("dob",QVariant(19781021));
    qInfo()<<settings.status(); //display eventual errors if any when saving
    qInfo()<<"The setting 'dob' was saved.";
}

void load(QSettings &settings)
{
    qInfo()<<settings.value("dob").toString(); //as a string
    bool conversionResult;
    qInfo()<<settings.value("dob").toInt(&conversionResult);

    if(!conversionResult)
    {
        qInfo()<<"Could not convert the value, sorry...";
    }
}

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    QCoreApplication::setOrganizationName("Freelancer");
    QCoreApplication::setOrganizationDomain("georgecalin.ro");
    QCoreApplication::setApplicationName("LearningSettings");

    QSettings settingsOject(QCoreApplication::organizationName(),QCoreApplication::applicationName());

    if(settingsOject.allKeys().length()==0)
    {
        qInfo()<<"No settings were saved before... saving now.";
        save(settingsOject);
    }
    else
    {
        qInfo()<<"Wow, it looks like settings are already saved, loading them now...";
        load(settingsOject);
    }


    return QCoreApplication::exec();
}

/*
No settings were saved before... saving now.
    QSettings::NoError
        The setting 'dob' was saved.

Wow, it looks like settings are already saved, loading them now...
    "19781021"
    19781021
 */
#include <QCoreApplication>
#include <QDebug>
#include <QDataStream>
#include <QFile>

bool write(QString filename)
{
    QFile file(filename);

    if(!file.open(QIODevice::OpenModeFlag::WriteOnly))
    {
        qInfo()<<"File was not open properly for writing.";
        qInfo()<<file.errorString();
        return false;
    }

    QDataStream stream(&file);
    stream.setVersion(QDataStream::Qt_6_11);

    int age = 47;
    QString name = "George Calin";
    double weight = 96.5;

    qInfo()<<"Writing to file now...";

    stream<<age<<name<<weight;


    if(!file.flush())
    {
        qInfo()<<file.errorString();
        file.close();
        return false;
    }

    qInfo()<<"Ï wrote to file...";

    qInfo()<<"closing the file...";
    file.close();

    return true;
}

bool read(QString filename)
{
    QFile file(filename);

    if(!file.open(QIODevice::OpenModeFlag::ReadOnly))
    {
        qInfo()<<"File is not opened properly";
        qInfo()<<file.errorString();
        return false;
    }

    QDataStream stream(&file);

    if(stream.version()!=QDataStream::Qt_6_11)
    {
        qInfo()<<"The encoding of the file is not in the desired version";
        return false;
    }

    int age = 0;
    QString name = "";
    double weight = 0.0;

    stream>>age;
    stream>>name;
    stream>>weight;

    file.close();

    qInfo()<<"read age= "<<age;
    qInfo()<<"read name= "<<name;
    qInfo()<<"read weight= "<<weight;

    return true;
}


int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    QString filename = "testfile.txt";

    if(write(filename))
    {
        read(filename);
    }


    return QCoreApplication::exec();
}

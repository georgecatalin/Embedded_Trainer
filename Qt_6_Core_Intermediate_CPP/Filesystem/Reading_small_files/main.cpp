#include <QCoreApplication>
#include <QDebug>
#include <QFile>

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    QString filename = "testfile.txt";

    QFile file(filename);

    qInfo()<<"Exists file?? "<<file.exists();

    if(file.open(QIODevice::OpenModeFlag::ReadOnly)) //ReadOnly allows multiple sources to read the file at the same time
    {
        qInfo()<<"File was opened correctly";

        qInfo()<<file.readAll();

        qInfo()<<"closing the file";
        file.close();
    }
    else
    {
        qInfo()<<file.errorString();
    }


    return QCoreApplication::exec();
}

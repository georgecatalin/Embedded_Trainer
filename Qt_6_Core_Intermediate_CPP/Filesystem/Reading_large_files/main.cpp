#include <QCoreApplication>
#include <QDebug>
#include <QFile>

void readLine(QFile &file)
{
    if(!file.isReadable()) return;

    file.seek(0);

    while(!file.atEnd())
    {
        qInfo()<<file.readLine();
    }
}

void readChunks(QFile &file)
{
    if(!file.isReadable()) return;
    file.seek(0);

    while(!file.atEnd())
    {
        qInfo()<<file.read(50);
    }

}



int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    QString filename = "testfile.txt";

    QFile file(filename);

    qInfo()<<"Exists?? "<<file.exists();


    if(file.open(QIODevice::OpenModeFlag::ReadOnly))
    {
        qInfo()<<"File was opened correctly.";

        readLine(file);

        qInfo()<<"-----------------------------";

        readChunks(file);

        qInfo()<<"Closing file.";
        file.close();
    }
    else
    {
        qInfo()<<file.errorString();
    }

    return QCoreApplication::exec();
}

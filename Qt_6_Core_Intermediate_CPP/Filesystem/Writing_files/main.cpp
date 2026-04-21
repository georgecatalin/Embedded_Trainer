#include <QCoreApplication>
#include <QFile>
#include <QDebug>
#include <QDateTime>

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    QString filename = "testfile.txt";

    QFile file(filename);


    if(file.open(QFile::OpenModeFlag::WriteOnly))
    {
        qInfo()<<"File was opened successfully.";

        QByteArray byteArray;

        QString dateNow = QDateTime::currentDateTime().toString();

        byteArray.append(dateNow.toLocal8Bit());
        byteArray.append(" - ");
        byteArray.append(" hello Mara");

        file.write(byteArray);

        qInfo()<<"closing the file";
        file.close();
    }
    else
    {
        qInfo()<<"File was not opened.";
    }

    return QCoreApplication::exec();
}

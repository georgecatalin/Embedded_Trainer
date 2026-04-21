#include <QCoreApplication>
#include <QDebug>
#include <QDateTime>
#include <QFile>

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);



    QString filename = "testfile.txt";
    QFile file(filename);

    qInfo()<<"Exists?? "<<file.exists();

    if(file.open(QIODevice::OpenModeFlag::Append))
    {
        qInfo()<<"File was opened";

        QByteArray data;

        QString datenow= QDateTime::currentDateTime().toString();
        data.append(datenow.toLocal8Bit());
        data.append(" -> ");
        data.append(" Hello, Mara!!\r\n"); //will be converted to UTF8

        qInfo()<<"Appending to file now...";
        file.write(data);


        qInfo()<<"Closing the file";
        file.close();
    }
    else
    {
        qInfo()<<"Could not open the file.";
        qInfo()<<file.errorString();
    }

    return QCoreApplication::exec();
}

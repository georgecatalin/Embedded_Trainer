#include <QCoreApplication>
#include <QDebug>
#include <QTextStream>
#include <QFile>

void write(QFile &file)
{
    if(!file.isWritable())
    {
        qInfo()<<"File is not writable.";
        return;
    }

    QTextStream stream(&file);
    stream.setEncoding(QStringConverter::LastEncoding);

    stream.seek(file.size()); //position the stream at the end of the file

    for (int i = 0; i < 10; ++i)
    {
        stream<<QString::number(i)<<"-item";
    }

    stream.flush();

    qInfo()<<"File written.";
}

void read(QFile &file)
{
    if(!file.isReadable())
    {
        qInfo()<<"File is not readable.";
        return;
    }

    QTextStream stream(&file);

    stream.seek(0);

    while(!stream.atEnd())
    {
        qInfo()<<stream.readLine();
    }
}

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);



    QString filename = "testfile.txt";



    QFile file(filename);

    QTextStream stream(&file);
    qInfo()<<"Extract the encoding:"<<stream.encoding();

    if(file.open(QIODevice::OpenModeFlag::ReadWrite))
    {
        qInfo()<<"File opened correctly";

        write(file);
        read(file);

        qInfo()<<"Closing file";
        file.close();
    }
    else
    {
        qInfo()<<file.errorString();
    }

    return QCoreApplication::exec();
}

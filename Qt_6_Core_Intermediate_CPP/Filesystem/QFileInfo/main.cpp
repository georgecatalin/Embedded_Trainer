#include <QCoreApplication>
#include <QDebug>
#include <QDir>
#include <QFileInfo>


void list(QString path)
{
    qInfo()<<"....Listing.....";

    QDir dir(path);
    QFileInfoList dirs = dir.entryInfoList(QDir::Filter::Dirs | QDir::Filter::NoDotAndDotDot,QDir::SortFlag::Name);
    QFileInfoList files = dir.entryInfoList(QDir::Filter::Files);

    foreach (QFileInfo fi, dirs)
    {
        qInfo()<<"Directory "<<fi.absoluteFilePath();
    }

    foreach (QFileInfo fi, files)
    {
        qInfo()<<"File "<<fi.filePath();
        qInfo()<<"File size "<<fi.size();
        qInfo()<<"File creation date"<<fi.birthTime();
        qInfo()<<"File modified on "<<fi.lastModified();
    }

    foreach (QFileInfo fi, dirs)
    {
        list(fi.absoluteFilePath());
    }
}


int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    QDir dir = QDir::tempPath();

    list(dir.absolutePath());

    return QCoreApplication::exec();
}

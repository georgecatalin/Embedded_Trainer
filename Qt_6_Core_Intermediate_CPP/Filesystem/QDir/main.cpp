#include <QCoreApplication>
#include <QDebug>
#include <QDir>
#include <QFileInfo>
#include <QFileInfoList>

void list(QDir &dir)
{
    qInfo()<<"----listing-------";
    foreach(QFileInfo fileInfo, dir.entryInfoList(QDir::Filter::Dirs | QDir::NoDotAndDotDot, QDir::Name))
    {
        if(fileInfo.isDir())
        {
            qInfo()<<fileInfo.absoluteFilePath();
        }
    }
}

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    QString dirpath = QCoreApplication::applicationDirPath();
    QDir dir(dirpath);

    qInfo()<<dir.dirName();
    qInfo()<<dir.absolutePath();

    qInfo()<<"List all the directories inside the dir";
    list(dir);

    dir.cdUp();
    qInfo()<<"Directory up one level...";
    qInfo()<<dir.absolutePath();

    list(dir);

    dir.mkdir("testdir");
    list(dir);

    //dir.rmdir("testdir");
    //list(dir);

    return QCoreApplication::exec();
}

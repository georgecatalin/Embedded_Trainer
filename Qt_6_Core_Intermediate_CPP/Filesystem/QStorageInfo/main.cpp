#include <QCoreApplication>
#include <QDebug>
#include <QStorageInfo>
#include <QDir>
#include <QFileInfo>


int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    QStorageInfo storage = QStorageInfo::root();

    qInfo()<<storage.rootPath();
    QDir root(storage.rootPath());

    foreach (QFileInfo fileinfo, root.entryInfoList(QDir::Filter::Dirs | QDir::Filter::NoDotAndDotDot,QDir::SortFlag::Name))
    {
        qInfo()<<fileinfo.fileName();
    }


    qInfo()<<"--------------------------------------";

    foreach (QStorageInfo storageInfo, QStorageInfo::mountedVolumes())
    {
        qInfo()<<"Name: "<<storageInfo.name();
        qInfo()<<"Display Name:"<<storageInfo.displayName();
        qInfo()<<"Filesystem Type: "<<storageInfo.fileSystemType();
        qInfo()<<"Total size in MB:"<<storageInfo.bytesTotal()/1000000;
        qInfo()<<"Free size in MB:"<<storageInfo.bytesFree()/1000000;
        qInfo()<<"Bytes available:"<<storageInfo.bytesAvailable()/1000000;
        qInfo()<<"Device:"<<storageInfo.device();
        qInfo()<<"Device name:"<<storageInfo.displayName();
    }

    return QCoreApplication::exec();
}

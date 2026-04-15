#include <QCoreApplication>
#include <QDebug>

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    QString full = "Hello from the Qt Course.";
    QStringList list = full.split(" ");

    foreach (QString variable, list)
    {
        qInfo()<<variable;

    }

    int indexOf = list.indexOf("Qet");

    if(indexOf==-1)
    {
        qInfo()<<"Searched string not found in "<<list;
    }
    else
    {
        qInfo()<<"String found at position "<<indexOf<<"->"<<list.value(indexOf);
    }

    return QCoreApplication::exec();
}

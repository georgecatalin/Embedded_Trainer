#include <QCoreApplication>
#include <QDebug>
#include <QSet>

//QSet<T> is another templated collection type in Qt which uses hashes for indexing and therefore it is quite fast

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    QSet<QString> family;
    family<<"George"<<"Mara"<<"Sorina";
    family.insert("Zizou");

    foreach (QString name, family)
    {
        qInfo()<<name;
    }

    qInfo()<<"Is Zizou in the family list? "<<family.contains("Zizou");

    return QCoreApplication::exec();
}




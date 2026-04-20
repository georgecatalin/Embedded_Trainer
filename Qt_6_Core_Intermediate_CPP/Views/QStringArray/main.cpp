#include <QCoreApplication>
#include <QDebug>
#include <QString>
#include <QStringView>

void display(QStringView &view)
{
    qInfo()<<view;
    qInfo()<<view.size();
    qInfo()<<view.count('l');
    qInfo()<<view.contains(QString("you"));
    qInfo()<<view.at(0);
    qInfo()<<view.indexOf('r');

    for (auto c : view)
    {
        qInfo()<<c;
    }
}

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    QString word("Hello, how are you ,alligator?");
    QStringView view(word);

    display(view);


    return QCoreApplication::exec();
}

/*
"Hello, how are you ,alligator?"
    30
    4
    true
    'H'
    12
    'H'
    'e'
    'l'
    'l'
    'o'
    ','
    ' '
    'h'
    'o'
    'w'
    ' '
    'a'
    'r'
    'e'
    ' '
    'y'
    'o'
    'u'
    ' '
    ','
    'a'
    'l'
    'l'
    'i'
    'g'
    'a'
    't'
    'o'
    'r'
    '?'
    */
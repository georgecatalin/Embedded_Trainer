#include <QCoreApplication>
#include <QDebug>
#include <QByteArray>
#include <QByteArrayView>


//We use Q**View classes to permit access to methods upon such object, but still protect from unwanted modifications

void testView(QByteArrayView &view)
{
    qInfo()<<view;

    qInfo()<<view.size();
    qInfo()<<view.contains("you");
    qInfo()<<view.at(0);
    qInfo()<<view.slice(1,4);
    qInfo()<<view.indexOf("h");

    for(auto c : view)
    {
        qInfo()<<c;
    }
}

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    QByteArray word("Hello, how are you?");
    QByteArrayView vWord(word);

    testView(vWord);

    return QCoreApplication::exec();
}

/*
"Hello, how are you?"
    19
    true
    H
    "ello"
    -1
    e
        l
            l
    o
*/
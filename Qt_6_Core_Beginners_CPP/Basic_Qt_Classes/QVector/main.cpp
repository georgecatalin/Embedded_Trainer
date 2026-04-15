#include <QCoreApplication>
#include <QDebug>

//QVector is an alias for QList in Qt 6

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    QString phrase = "Learning a little each day adds up. Research shows that students who make learning a habit are more likely to reach their goals."
                     " Set time aside to learn and get reminders using your learning scheduler.";
    QVector<QString> list = phrase.split(" ");

    foreach (QString var, list)
    {
        qInfo()<<var;
    }

    QVector<int> listInts({1977,1978,2011,2020,1954,1953});

    foreach (int var, listInts)
    {
        qInfo()<<var;
    }

    listInts.append(2);
    qInfo()<<listInts;

    listInts.remove(0);
    qInfo()<<listInts;

    return QCoreApplication::exec();
}

/*
"Learning"
    "a"
    "little"
    "each"
    "day"
    "adds"
    "up."
    "Research"
    "shows"
    "that"
    "students"
    "who"
    "make"
    "learning"
    "a"
    "habit"
    "are"
    "more"
    "likely"
    "to"
    "reach"
    "their"
    "goals."
    "Set"
    "time"
    "aside"
    "to"
    "learn"
    "and"
    "get"
    "reminders"
    "using"
    "your"
    "learning"
    "scheduler."
    1977
    1978
    2011
    2020
    1954
    1953
    QList(1977, 1978, 2011, 2020, 1954, 1953, 2)
    QList(1978, 2011, 2020, 1954, 1953, 2)
    */
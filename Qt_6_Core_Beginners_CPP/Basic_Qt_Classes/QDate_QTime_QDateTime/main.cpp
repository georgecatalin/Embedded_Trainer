#include <QCoreApplication>
#include <QDebug>
#include <QDate>
#include <QTime>
#include <QDateTime>

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    QDate todayDate = QDate::currentDate();
    qInfo()<<todayDate;
    qInfo()<<todayDate.addDays(10);
    qInfo()<<"The date is "<<todayDate.toString(Qt::DateFormat::ISODate);
    qInfo()<<"The date is "<<todayDate.toString(Qt::DateFormat::ISODateWithMs);
    qInfo()<<"The date is "<<todayDate.toString(Qt::DateFormat::TextDate);
    qInfo()<<"The date is "<<todayDate.toString(Qt::DateFormat::RFC2822Date);

    QTime currentTime = QTime::currentTime();
    qInfo()<<currentTime;
    qInfo()<<currentTime.addSecs(3600);
    qInfo()<<"The time is "<<currentTime.toString(Qt::DateFormat::ISODate);
    qInfo()<<"The time is "<<currentTime.toString(Qt::DateFormat::ISODateWithMs);
    qInfo()<<"The time is "<<currentTime.toString(Qt::DateFormat::TextDate);
    qInfo()<<"The time is "<<currentTime.toString(Qt::DateFormat::RFC2822Date);

    QDateTime currentDateTime = QDateTime::currentDateTime();
    qInfo()<<currentDateTime;
    qInfo()<<"The datetime is "<<currentDateTime.toString(Qt::DateFormat::ISODate);
    qInfo()<<"The datetime is "<<currentDateTime.toString(Qt::DateFormat::ISODateWithMs);
    qInfo()<<"The datetime is "<<currentDateTime.toString(Qt::DateFormat::TextDate);
    qInfo()<<"The datetime is "<<currentDateTime.toString(Qt::DateFormat::RFC2822Date);

    QDateTime expiryDateTime = currentDateTime.addDays(10);
    qInfo()<<"The expiry date is "<<expiryDateTime;

    return QCoreApplication::exec();
}

/*
QDate("2026-04-15")
QDate("2026-04-25")
The date is  "2026-04-15"
The date is  "2026-04-15"
The date is  "Wed Apr 15 2026"
The date is  "15 Apr 2026"
QTime("11:07:09.141")
QTime("12:07:09.141")
The time is  "11:07:09"
The time is  "11:07:09.141"
The time is  "11:07:09"
The time is  "11:07:09"
QDateTime(2026-04-15 11:07:09.142 GMT+3 Qt::LocalTime)
The datetime is  "2026-04-15T11:07:09"
The datetime is  "2026-04-15T11:07:09.142"
The datetime is  "Wed Apr 15 11:07:09 2026"
The datetime is  "15 Apr 2026 11:07:09 +0300"
The expiry date is  QDateTime(2026-04-25 11:07:09.142 GMT+3 Qt::LocalTime)
*/
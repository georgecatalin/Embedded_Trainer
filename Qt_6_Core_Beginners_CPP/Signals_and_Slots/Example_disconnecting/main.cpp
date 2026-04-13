#include <QCoreApplication>
#include <QDebug>
#include <QTextStream>
#include <QString>
#include "radio.h"
#include "station.h"

using namespace std;

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    Radio radio; //radio create on the stack

    Station *stations[3];

    stations[0] = new Station(&radio, 99,"Radio Alfa");
    stations[1] = new Station(&radio, 108, "Radio Galati");
    stations[2] = new Station(&radio,101,"Magic FM");

    QObject::connect(&radio,&Radio::quit,&a,&QCoreApplication::quit,Qt::QueuedConnection);

    while(true)
    {
        QTextStream myInput(stdin);
        QString inputText = myInput.readLine().trimmed().toUpper();

        if(inputText == "ON")
        {
            qInfo()<<"Power set to ON";
            for (int i = 0; i < 3; ++i)
            {
                QObject::connect(stations[i],&Station::send,&radio,&Radio::listen);
            }
        }
        else if(inputText == "OFF")
        {
            qInfo()<<"Power is OFF";
            for (int i = 0; i < 3; ++i)
            {
                QObject::disconnect(stations[i],&Station::send,&radio,&Radio::listen);
            }
        }
        else if(inputText == "TEST")
        {
            qInfo()<<"System is testing...";
            for (int i = 0; i < 3; ++i)
            {
                stations[i]->broadcast("Hello from station");
            }
            qInfo()<<"Completed the tests";
        }
        else if(inputText == "QUIT")
        {
            qInfo()<<"System is quitting now...";
            emit radio.quit();
            break;
        }

    }

    return a.exec();
}

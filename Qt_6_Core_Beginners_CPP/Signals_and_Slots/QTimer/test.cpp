#include "test.h"

Test::Test(QObject *parent) : QObject{parent}
{
    QObject::connect(&m_timer,&QTimer::timeout,this,&Test::timeout);
    counter = 0;

    m_timer.setInterval(1000);
    m_timer.start();
}

void Test::timeout()
{
    qInfo()<<"Timeout.."<<counter;
    counter++;

    if(counter >=10)
    {
        m_timer.stop();
        qInfo()<<"We are done!!";
    }

}

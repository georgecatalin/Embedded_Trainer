#include "destination.h"

Destination::Destination(QObject *parent) : QObject{parent}
{
    qInfo()<< this << " Destination object constructed.";
}

void Destination::mySlot(QString message_to_receive)
{
    qInfo()<<this<<" received the message "<<message_to_receive;
}

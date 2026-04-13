#include "owner.h"

Owner::Owner(QObject *parent)
    : QObject{parent}
{}

void Owner::giveSnack()
{
    qInfo()<<"Owner gives snack.";
    emit treats();
}

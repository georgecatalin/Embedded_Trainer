#ifndef LION_H
#define LION_H

#include <QObject>
#include <QDebug>
#include "feline.h"

class Lion : public Feline
{
public:
     explicit Lion(QObject *parent = nullptr);
    void speak();
};

#endif // LION_H

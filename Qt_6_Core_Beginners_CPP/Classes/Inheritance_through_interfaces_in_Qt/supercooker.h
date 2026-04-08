#ifndef SUPERCOOKER_H
#define SUPERCOOKER_H

#include <QObject>
#include <QDebug>
#include "Toaster.h"
#include "Freezer.h"
#include "Microwave.h"

class Supercooker : public QObject, public Toaster, public Freezer, public Microwave
{
    Q_OBJECT
public:
    explicit Supercooker(QObject *parent = nullptr);

    // Microwave interface
    bool Cook();

    // Freezer interface
    bool freeze();

    // Toaster interface
    bool toast();

signals:
};

#endif // SUPERCOOKER_H

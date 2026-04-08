#ifndef HYBRID_H
#define HYBRID_H

#include <QObject>
#include "canine.h"

//NOTE: Multiple inheritance is not supported in Qt through classes, only through interfaces. If one inherits from two classes, error during build process
class Hybrid : public Canine
{
    Q_OBJECT
public:
    explicit Hybrid(QObject *parent = nullptr);
    void attacks();

signals:
};

#endif // HYBRID_H

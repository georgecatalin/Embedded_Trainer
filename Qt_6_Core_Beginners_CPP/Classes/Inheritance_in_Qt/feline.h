#ifndef FELINE_H
#define FELINE_H

#include <QObject>
#include "animal.h"

class Feline : public Animal
{
    Q_OBJECT
public:
    explicit Feline(QObject *parent = nullptr);
    void miaows();

signals:
};

#endif // FELINE_H

#ifndef _RHOMBUS_H
#define _RHOMBUS_H

#include <iostream>
#include "shape.h"


class Rhombus: virtual public Shape
{
    private:
        float angle;
    public:
        Rhombus();
        ~Rhombus();
        void print();
};

  
#endif
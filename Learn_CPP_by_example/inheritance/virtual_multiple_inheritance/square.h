#ifndef _SQUARE_H
#define _SQUARE_H

#include <iostream>
using namespace std;

#include "rectangle.h"
#include "rhombus.h"

class Square:public Rectangle, public Rhombus
{
    public:
        Square();
        ~Square();
        void print();
};


#endif
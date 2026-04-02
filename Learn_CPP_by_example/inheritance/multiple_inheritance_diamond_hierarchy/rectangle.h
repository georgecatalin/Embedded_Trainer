#ifndef _RECTANGLE_H
#define _RECTANGLE_H

#include <iostream>
#include "shape.h"

using namespace std;

class Rectangle : public Shape
{
    public:
        float length;
        float breadth;
        Rectangle();
        ~Rectangle();
        void print();
};




#endif
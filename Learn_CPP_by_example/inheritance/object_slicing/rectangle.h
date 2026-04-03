#ifndef _RECTANGLE_H
#define _RECTANGLE_H

#include <iostream>
#include "shape.h"

using namespace std;

class Rectangle: public Shape
{
    private:
        int length;
        int breadth;
    public:
        Rectangle();
        ~Rectangle();
        void print() const;
};


void printSliced(Shape s);
void printUnsliced(const Shape& s);



#endif
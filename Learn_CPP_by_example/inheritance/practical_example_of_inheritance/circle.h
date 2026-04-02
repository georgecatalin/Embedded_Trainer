#ifndef _CIRCLE_H
#define _CIRCLE_H

#include <iostream>
#include "shape.h"


using namespace std;

class Circle : public Shape
{
    private:
        float radius;
    public:
        Circle();
        Circle(string shape_type, float r);
        Circle(const Circle& rhs);
        ~Circle();
        Circle& operator=(const Circle& rhs);
};



#endif
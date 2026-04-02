#ifndef _CIRCLE_H
#define _CIRCLE_H

#include "shape.h"
using namespace std;

class Circle:public Shape
{
    private:
        float radius;
    public:
        Circle();
        Circle(string shape_type, float radius);
        Circle(const Circle& rhs);
        ~Circle();
        void print();
        Circle& operator=(const Circle& rhs);

};




#endif
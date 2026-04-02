#ifndef _SHAPE_H
#define _SHAPE_H

#include <iostream>
using namespace std;


class Shape
{
    private:
        string shape_type;
    public:
        Shape();
        Shape(string shape_type);
        Shape(const Shape& rhs);
        ~Shape();
        Shape& operator=(const Shape& rhs);
};



#endif
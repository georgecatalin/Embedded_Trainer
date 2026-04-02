#ifndef _SHAPE_H
#define _SHAPE_H

#include <iostream>
using namespace std;


class Shape //this is an abstract class, cause it has a pure virtual function
{
    private:
        string shapeType;
    public:
        Shape();
        ~Shape();
        virtual void print() = 0; //pure virtual method
};



#endif
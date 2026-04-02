#ifndef _SHAPE_H
#define _SHAPE_H

#include <iostream>
using namespace std;

class Shape_Abstract //contains at least one virtual method with no implementation
{
    private:
        string shapeType;
    public:
        virtual void print() = 0; //this is a pure virtual function, no implementation exists for this class.thus this class can not be instantianted
};



#endif
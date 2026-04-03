#ifndef _SHAPE_H
#define _SHAPE_H

#include <iostream>
using namespace std;



class Shape
{
    private:
    public:
      string shapeType;
      Shape();
      ~Shape();
      virtual void print() const;

};



#endif
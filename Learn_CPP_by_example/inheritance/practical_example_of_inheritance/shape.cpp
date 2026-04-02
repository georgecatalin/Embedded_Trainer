#include "shape.h"

Shape::Shape()
{
    cout<<"SHAPE: Inside of the no-argument constructor"<<endl;
}


Shape::Shape(string shape_type): shape_type(shape_type)
{
    cout<<"SHAPE: Inside the 1-argument constructor ->"<<shape_type<<endl;
}

Shape::Shape(const Shape& rhs) : shape_type(rhs.shape_type)
{
   cout<<"SHAPE: Inside the copy-constructor "<<endl;
}


Shape::~Shape()
{
    cout<<"SHAPE: Inside the destructor of the object ->"<<shape_type<<endl;
}


Shape& Shape::operator=(const Shape& rhs)
{
   cout<<"SHAPE: Inside the overloading of the assignment operator"<<endl;

   if(this!=&rhs)
   {
      shape_type = rhs.shape_type;
   }

   return *this;
}
#include "shape.h"


Shape::Shape()
{
    cout<<"SHAPE: Inside of the no-argument constructor"<<endl;
}

Shape::Shape(string shape_type) :shape_type(shape_type)
{
    cout<<"SHAPE: Inside of the 1-argument constructor"<<endl;
}

Shape::Shape(const Shape& rhs): shape_type(rhs.shape_type)
{
    cout<<"SHAPE: Inside of the copy constructor"<<endl;
}

Shape::~Shape()
{
    cout<<"SHAPE: Inside of the destructor for object ->"<<shape_type<<endl;
}

Shape& Shape::operator=(const Shape& rhs)
{
    cout<<"SHAPE: Inside of the overload for the assignment operator"<<endl;

    if(this!=&rhs)
    {
        shape_type = rhs.shape_type;
    }

    return *this;
}

void Shape::print()
{
    cout<<"SHAPE: I do not know my shape"<<endl;
}
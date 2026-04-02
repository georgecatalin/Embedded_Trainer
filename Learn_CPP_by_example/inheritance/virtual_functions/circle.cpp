#include "circle.h"

Circle::Circle()
{
    cout<<"CIRCLE: Inside of the no-argument constructor"<<endl;
}

Circle::Circle(string shape_type, float r): Shape(shape_type),radius(r)
{
    cout<<"CIRCLE: Inside of the 1-argument constructor"<<endl;
}

Circle::Circle(const Circle& rhs) : Shape(rhs), radius(rhs.radius)
{
    cout<<"CIRCLE: Inside of the copy constructor"<<endl;
}

Circle& Circle::operator=(const Circle& rhs)
{
    cout<<"CIRCLE: Inside of the overload for the assignment operator"<<endl;

    if(this!=&rhs)
    {
        this->Shape::operator=(rhs);
        radius = rhs.radius;
    }

    return *this;
}

void Circle::print()
{
    cout<<"CIRCLE: I am a circle"<<endl;
}
#include "circle.h"

Circle::Circle()
{
    cout << "CIRCLE: Inside the no-constructor argument" << endl;
}

Circle::Circle(string shape_type, float r) : Shape(shape_type), radius(r)
{
    cout << "CIRCLE: Inside the 1-constructor argument" << endl;
}

Circle::Circle(const Circle &rhs): Shape(rhs), radius(rhs.radius)
{
    cout << "CIRCLE: Inside the copy constructor" << endl;
}

Circle::~Circle()
{
    cout << "CIRCLE: Inside the destructor" << endl;
}

Circle &Circle::operator=(const Circle &rhs)
{
    cout << "CIRCLE: Inside the overloading of the assignment operator" << endl;

    if (this != &rhs)
    {
        this->Shape::operator=(rhs);
        radius = rhs.radius;
    }

    return *this;
}
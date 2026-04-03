#include "rectangle.h"


Rectangle::Rectangle()
{
    cout<<"RECTANGLE: I am inside the constructor"<<endl;
}

Rectangle::~Rectangle()
{
    cout<<"RECTANGLE: I am inside the destructor"<<endl;
}

void Rectangle::print() const
{
    cout<<"RECTANGLE: I am an object of size "<<sizeof(*this)<<" bytes"<<endl;
}

void printSliced(Shape s)
{
    cout<<"this function will occur with object slicing -> only the base class part of the object will be passed, constructor and destructor only of it."<<endl;
    s.print(); //runs print() from Shape class
}


void printUnsliced(const Shape &s)
{
    cout<<"This function will occur without slicing, constructor and destructors will apply to both derived and base class"<<endl;
    s.print(); //runs print() for the class what the object belongs to
}
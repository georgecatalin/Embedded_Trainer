#include "new_place.h"

ComplexNumber::ComplexNumber(): real_part(0), imaginary_part(0)
{
    cout<<"No argument constructor called here"<<endl;
}

ComplexNumber::ComplexNumber(float r, float i): real_part(r), imaginary_part(i)
{
    cout<<"2 argument constructor called here "<<endl;
}

ComplexNumber::ComplexNumber(const ComplexNumber& obj) : real_part(obj.real_part), imaginary_part(obj.imaginary_part)
{
    cout<<"Copy constructor called here"<<endl;
}

void ComplexNumber::print()
{
    cout<<"The object is "<<real_part<<" +i "<<imaginary_part<<endl;
}

ComplexNumber::~ComplexNumber()
{
    cout<<"destructor called for object "<<real_part<<" +i "<<imaginary_part<<endl;
}


#include "new.h"

ComplexNumber::ComplexNumber(): real_part(0), imaginary_part(0)
{
    cout<<"no argument constructor called "<<endl;
}

ComplexNumber::ComplexNumber(float r, float i) : real_part(r), imaginary_part(i)
{
    cout<<"2 argument constructor called "<<endl;
}

ComplexNumber::ComplexNumber(const ComplexNumber& obj) : real_part(obj.real_part), imaginary_part(obj.imaginary_part)
{
    cout<<"copy constructor called "<<endl;
}

void ComplexNumber::print()
{
    cout<<"Complex number printed -> "<<real_part<<" + i"<<imaginary_part<<endl;
}

ComplexNumber::~ComplexNumber()
{
    cout<<"Destructor called for object "<<real_part<<" + i"<<imaginary_part<<endl;
}
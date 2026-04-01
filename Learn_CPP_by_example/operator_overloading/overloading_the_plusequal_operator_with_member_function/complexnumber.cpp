#include "complexnumber.h"


ComplexNumber::ComplexNumber() : real_part(0), imaginary_part(0)
{
    cout<<"Inside of the 0-argument constructor"<<endl;
}

ComplexNumber::ComplexNumber(float r, float i) : real_part(r), imaginary_part(i)
{
    cout<<"Inside the 2-argument constructor"<<endl;
}

ComplexNumber::ComplexNumber(const ComplexNumber& rhs) : real_part(rhs.real_part), imaginary_part(rhs.imaginary_part)
{
    cout<<"Inside the copy constructor"<<endl;
}

ComplexNumber::~ComplexNumber()
{
    cout<<"Inside the destructor of the object ("<<real_part<<","<<imaginary_part<<")"<<endl;
}

ComplexNumber& ComplexNumber::operator+=(const ComplexNumber& rhs)
{
    this->real_part += rhs.real_part;
    this->imaginary_part += rhs.imaginary_part;
    return *this;
}

void ComplexNumber::print()
{
    cout<<"Object description \n("<<real_part<<","<<imaginary_part<<")"<<endl;
}
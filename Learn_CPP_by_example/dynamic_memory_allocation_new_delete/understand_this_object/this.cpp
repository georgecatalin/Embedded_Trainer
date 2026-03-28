#include "this.h"

 ComplexNumber::ComplexNumber(): real_part(0), imaginary_part(0)
    {
        cout<<"no argument constructor was called"<<endl;
    }

 ComplexNumber::ComplexNumber(float r, float i) : real_part(r), imaginary_part(i)
    {
        cout<<"2 arguments constructor was called "<<endl;
    }

 ComplexNumber::ComplexNumber(const ComplexNumber& obj) : real_part(obj.real_part), imaginary_part(obj.imaginary_part)
    {
        cout<<"Copy constructor was called "<<endl;
    }

void ComplexNumber::print()
    {
        cout<<"Object is "<<real_part<<"+i"<<imaginary_part<<"."<<endl;
    }

void ComplexNumber::printThis()
    {
        cout<<"The memory address where this object lies is "<<this<<endl;
        cout<<"The object is "<<this->real_part<<" +i"<<this->imaginary_part<<endl;
    }

ComplexNumber:: ~ComplexNumber()
    {
        cout<<"The destructor was called for the object "<<real_part<<" +i"<<imaginary_part<<endl;
    }
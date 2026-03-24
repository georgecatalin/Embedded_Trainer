#include "complex_number.h"

using namespace std;

int ComplexNumber::number_of_objects = 0;
const float ComplexNumber::PI = 3.14f;

ComplexNumber::ComplexNumber() : real_part(0.0), imaginary_part(0.0)
{
    number_of_objects ++;
    cout<<"No arguments constructor called "<< endl;
}

ComplexNumber::ComplexNumber(float r, float i) : real_part(r), imaginary_part(i)
{
    number_of_objects ++;
    cout<<"2 arguments constructor called for "<<real_part<<" +i"<<imaginary_part<<endl;
}

ComplexNumber::ComplexNumber(const ComplexNumber& obj) : real_part(obj.real_part), imaginary_part(obj.imaginary_part)
{
    number_of_objects ++;
    cout<<"Copy constructor called here "<<endl;
}


float ComplexNumber::get_real_part()
{
    return real_part;
}

float ComplexNumber::get_imaginary_part()
{
    return imaginary_part;
}

void ComplexNumber::set_real_part(float r)
{
    real_part = r;
}

void ComplexNumber::set_imaginary_part(float i)
{
    imaginary_part = i;
}

void ComplexNumber::print()
{
    cout<<"object created "<<real_part<<" +i"<<imaginary_part<<endl;
}

ComplexNumber::~ComplexNumber()
{
    cout<<"Destructor called for object "<<real_part<<" +i"<<imaginary_part<<endl;
}
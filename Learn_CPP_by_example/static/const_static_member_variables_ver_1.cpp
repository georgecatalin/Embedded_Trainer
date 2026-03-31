#include "const_static_member_variables_ver_1.h"


/*
option 1: declare the const static member variables in the class, define it outside the class (supported by all compilers)
*/


const float ComplexNumber::NATO = 5.56;
 
ComplexNumber::ComplexNumber(): realPart(0), imaginaryPart(0)
{
    cout<<"no argument constructor was called"<<endl;

}

ComplexNumber::ComplexNumber(float r, float i): realPart(r), imaginaryPart(i)
{
    cout<<"2 argument constructor was called"<<endl;

}

ComplexNumber::ComplexNumber(const ComplexNumber& rhs): realPart(rhs.realPart), imaginaryPart(rhs.imaginaryPart)
{
    cout<<"copy constructor was called"<<endl;
}

ComplexNumber::~ComplexNumber()
{
    cout<<"Destructor was called"<<endl;
}

int main(void)
{
   cout<<"const static member variable outside the class ->>"<<ComplexNumber::NATO<<endl;

    return 0;
}
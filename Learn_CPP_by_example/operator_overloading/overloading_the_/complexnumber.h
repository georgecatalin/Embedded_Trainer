#ifndef _COMPLEX_NUMBER_H
#define _COMPLEX_NUMBER_H

#include <iostream>

using namespace std;


class ComplexNumber
{
   private:
    float real_part;
    float imaginary_part;
    public:
    ComplexNumber();
    ComplexNumber(float r, float i);
    ComplexNumber(const ComplexNumber& rhs);
    ~ComplexNumber();

    void print();
};


#endif
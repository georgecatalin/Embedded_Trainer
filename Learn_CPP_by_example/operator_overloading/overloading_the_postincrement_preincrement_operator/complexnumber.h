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

    ComplexNumber& operator++(); //preincrement operator  why not const? to resemble with operator behaviour for natural C++ like ints ++++a works
    const ComplexNumber operator++(int dummy);// 'dummy' argument is not actually used, it only denotes overloading the function by changing the argument  to be different from the preincrement
    //also we use const ComplexNumber as return type because there will be a new object created, and a++ = b should not work
    

};


#endif
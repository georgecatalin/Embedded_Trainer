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

    friend  ostream& operator<<(ostream& outputStream, const ComplexNumber& complexNumber); // allow the function to access its private member variables
    friend istream& operator>>(istream& inputStream, ComplexNumber& complexNumber); // alllow the function to access its private member variables
};

ostream& operator<<(ostream& outputStream, const ComplexNumber& complexNumber);
istream& operator>>(istream& inputStream, ComplexNumber& complexNumber);

#endif
#ifndef _THIS_H
#define _THIS_H

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
    ComplexNumber(const ComplexNumber& obj) ;
    void print();
    void printThis();
    ~ComplexNumber();
};


#endif
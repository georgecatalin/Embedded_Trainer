#ifndef _NEW_PLACE_H
#define _NEW_PLACE_H

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
        ComplexNumber(const ComplexNumber& obj);
        void print();
        ~ComplexNumber();
};


#endif
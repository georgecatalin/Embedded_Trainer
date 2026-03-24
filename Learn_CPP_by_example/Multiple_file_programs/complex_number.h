#ifndef _COMPLEX_H
#define _COMPLEX_H

#include <iostream>
#include <cmath>
#include <cstring>

class ComplexNumber
{
    private:
        float real_part;
        float imaginary_part;
    public:
        static int number_of_objects;
        const static float PI;

        ComplexNumber();
        ComplexNumber(float r, float i);
        ComplexNumber(const ComplexNumber& obj);

        float get_real_part();
        float get_imaginary_part();

        void set_real_part(float r);
        void set_imaginary_part(float i);

        void print();

        ~ComplexNumber();
};


#endif
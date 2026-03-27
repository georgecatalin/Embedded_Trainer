#ifndef _NO_MALLOC_H_
#define _NO_MALLOC_H_

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

#endif /* _NO_MALLOC_H_ */
#include <iostream>

using namespace std;

/*
1. declare the static member variable inside the class
2. define the static member variable outside the class
3. make use of the static member variable inside the class
4. use the static member variable outside the class provided it is visible
*/

/*
option 1: declare the const static member variables in the class, define it outside the class (supported by all compilers)
*/

class ComplexNumber
{
    private:
        float realPart;
        float imaginaryPart;
    public:
        const static float NATO;
        ComplexNumber();
        ComplexNumber(float r, float i);
        ComplexNumber(const ComplexNumber& rhs);
        ~ComplexNumber();
};
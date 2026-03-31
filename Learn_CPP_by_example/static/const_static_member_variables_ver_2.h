#include <iostream>

using namespace std;

/*
1. declare the static member variable inside the class
2. define the static member variable outside the class
3. make use of the static member variable inside the class
4. use the static member variable outside the class provided it is visible
*/

/*
option 2: define the const static member variables in the class, define it as a dummy outside the class (supported by new compilers only)
*/

class ComplexNumber
{
    private:
        float realPart;
        float imaginaryPart;
    public:
        constexpr static float NATO = 5.56;
        ComplexNumber();
        ComplexNumber(float r, float i);
        ComplexNumber(const ComplexNumber& rhs);
        ~ComplexNumber();
};
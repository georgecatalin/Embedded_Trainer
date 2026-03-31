#include <iostream>

using namespace std;

class ComplexNumber
{
    private:
        float realPart;
        float imaginaryPart;
        static int numberObjectsCreated;
    public:
        static int getNumberObjectsCreated();
        ComplexNumber();
        ComplexNumber(float r, float i);
        ComplexNumber(const ComplexNumber& rhs);
        ~ComplexNumber();
};
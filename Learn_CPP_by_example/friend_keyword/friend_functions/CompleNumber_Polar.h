#include <iostream>
#include <math.h>

using namespace std;

class ComplexNumber; //forward declaration before setting as parameter in the friend function down below 

class ComplexNumber_Polar
{
private:
    float modulus;
    float argument;

public:
    ComplexNumber_Polar(double r, double theta);

    float getModulus() const;
    void setModulus(float r);

    float getArgument() const;
    void setArgument(float theta);

    friend ComplexNumber addTwoComplexNumbers(const ComplexNumber &cart, const ComplexNumber_Polar &polar); //by marking this as friend, i am allowing it to access my private member variables inside this class
};
};
#include "ComplexNumber.h"
#include "CompleNumber_Polar.h"

ComplexNumber addTwoComplexNumbers(const ComplexNumber &cart, const ComplexNumber_Polar &polar)
{
    float realPart = polar.modulus * cos(polar.argument * ComplexNumber::PI / 180);
    float complexPart = polar.modulus * sin(polar.argument * ComplexNumber::PI / 180);

    ComplexNumber result(realPart + cart.realPart, complexPart + cart.complexPart); //fire at this point the 2-arguments constructor as well
    return result;
}

int main(void)
{
    ComplexNumber cart(5, 5);
    ComplexNumber_Polar polar(10, 45);

    ComplexNumber sumOfTwoComplexNumbers = addTwoComplexNumbers(cart, polar);

    cout << "Real part = " << sumOfTwoComplexNumbers.getRealPart()
         << "Complex part = " << sumOfTwoComplexNumbers.getComplexPart() << endl;

    return 0;
}
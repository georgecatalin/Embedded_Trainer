#include "complexnumber.h"

int main(void)
{
    ComplexNumber c1(5.56,45);
    ComplexNumber c2(7.62,46);

    c1.print();
    c2.print();
    c1 += c2;
    c1.print();

    return 0;
}
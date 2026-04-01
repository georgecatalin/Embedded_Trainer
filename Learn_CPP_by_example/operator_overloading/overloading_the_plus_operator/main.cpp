#include "complexnumber.h"

int main(void)
{
   ComplexNumber c1(5.56,45); //NATO standard
   ComplexNumber c2(7.62,51); //NATO standard

   c1.print();
   c2.print();

   ComplexNumber c3 = c1 + c2;
   c3.print();


    return 0;
}
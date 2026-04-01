#include "complexnumber.h"

int main(void)
{
    ComplexNumber c1(5.45,39);
    c1.print();

    cout<<"pre-increment operator applied"<<endl;

    ComplexNumber c2 = ++c1;
    c2.print(); // 6.45, 40
    c1.print(); // 6.45, 40

    cout<<"post-increment operator applied"<<endl;

    ComplexNumber c3 = c1++;
    c3.print(); //6.45, 40
    c1.print(); //7.45, 41


    return 0;
}
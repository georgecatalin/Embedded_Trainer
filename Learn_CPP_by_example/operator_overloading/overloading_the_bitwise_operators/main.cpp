#include "complexnumber.h"

int main(void)
{
    ComplexNumber c1(5.56,45);
    c1.print();

    cout<<c1<<endl;

    cin>>c1;
    cout<<"after cin "<<c1<<endl;


    return 0;
}
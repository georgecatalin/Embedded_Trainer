#include "complex_number.h"

using namespace std;

int main()
{
    ComplexNumber c1;

    c1.print();

    ComplexNumber c2(1978,2011);
    c2.print();

    ComplexNumber c3 = c2;
    c3.print();

    cout<<"completed execution of main()"<<endl;

    return 0;
}
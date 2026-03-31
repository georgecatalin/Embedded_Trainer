#include <iostream>

using namespace std;


int main(void)
{
    int age = 14;
    const int& ref_age = age;

    cout<<"Initial value of age ="<<age<<" and reference ref_age ="<<ref_age<<endl;

    age += 10;
    cout<<"Further value of age ="<<age<<" and reference ref_age ="<<ref_age<<endl;

    ref_age = 47; // error cause ref_age can not be assigned to a new value as it is set as 'const'

    /*
    expression must be a modifiable lvalue
    */

    return 0;
}
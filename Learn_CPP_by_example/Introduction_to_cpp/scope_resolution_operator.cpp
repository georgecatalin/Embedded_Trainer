#include <iostream>

using namespace std;

int age = 73;

namespace georges_space
{
    int age = 47;
}

int main()
{
    int age = 14;
    cout<<"Hello from C++"<<endl;

    cout<<"The local variable 'a' is "<<age<<endl; // searches for the local variable if it exists, if not, it goes global
    cout<<"The global variable 'a' is "<<::age<<endl; // searches in the global namespace (std) and takes the value, if not, it gets to the next defined namespace until it finds the var
    cout<<"The specific namespace variable 'a' is "<<georges_space::age<<endl;

    return 0;
}
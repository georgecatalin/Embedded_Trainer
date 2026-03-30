#include <iostream>

using namespace std;



int main(void)
{
    int *x = new int(1978);
    int* &y = x; // this is a reference to an int pointer

    cout<<"the values:\n*x="<<*x<<"*y="<<*y<<endl;



    return 0;
}
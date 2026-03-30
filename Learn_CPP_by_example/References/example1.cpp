#include <iostream>

using namespace std;

int main(void)
{
    int x = 1978;
    int&y = x; //always references have to be initialized

    cout<<"The value of x ="<<x<<" and the value of y="<<y<<endl;

    y = 2011;
    cout<<"The value of x ="<<x<<" and the value of y="<<y<<endl;

    x = 1954;
    cout<<"The value of x ="<<x<<" and the value of y="<<y<<endl;




    return 0;
}
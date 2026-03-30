#include <iostream>

using namespace std;



int main(void)
{
    int x = 2011;
    int z = 1954;

    int& y = x;


    cout<<"x="<<x<<" y="<<y<<" z="<<z<<endl; //2011 2011 1954

    //reassignment
    // once assigned , a reference is not being reassigned, it only takes the new value
    y = z; // y takes value of z which is 1954, and since y is the reference of x , x gets 1954
    cout<<"x="<<x<<" y="<<y<<" z="<<z<<endl; // 1954 1954 1954

    y = 1977;
    cout<<"x="<<x<<" y="<<y<<" z="<<z<<endl; // 1977 1977 1954






    return 0;
}
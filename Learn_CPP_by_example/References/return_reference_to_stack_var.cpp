#include <iostream>

using namespace std;

int& badfunction()
{
    int x(47);
    return x;
}

int main(void)
{
   int myvar = badfunction();

   //myvar does not exist anymore on the stack after the function returned, thus Segmentation fault (core dumped)

   cout<<"The value of myvar ="<<myvar<<endl;



    return 0;
}
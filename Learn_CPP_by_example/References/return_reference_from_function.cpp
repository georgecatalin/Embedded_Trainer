#include <iostream>

using namespace std;

//bad practice never return reference from a function
int& badpracticefunction()
{
    int *number = new int(2011);
    return *number;
}

int main(void)
{
    int this_number = badpracticefunction();

    cout<<"The number returned from the function is "<<this_number<<endl;

    //since there is no delete, there will be a memory leak


    return 0;
}
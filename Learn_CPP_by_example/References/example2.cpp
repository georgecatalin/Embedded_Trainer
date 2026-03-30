#include <iostream>

using namespace std;

void swap_with_pointers(int *a, int *b)
{
   int temporary = *a;
   *a = *b;
   *b = temporary;

}


void swap_with_references(int& a, int& b)
{
   int temporary = a;
   a = b;
   b = temporary; 
}

int main(void)
{
    int x = 1978;
    int y = 2011;

    cout<<"The value of x before swapping with pointers x= "<<x<<" the value of y before swapping with pointers y="<<y<<endl;

    swap_with_pointers(&x,&y);

    cout<<"The value of x after swapping with pointers x="<<x<<" the value of y after swapping with pointers y="<<y<<endl;


    cout<<"The value of x before swapping with references x="<<x<<" the value of y before swapping with references y="<<y<<endl;

    swap_with_pointers(&x,&y);

    cout<<"The value of x after swapping with references x="<<x<<" the value of y after swapping with references y="<<y<<endl;




    return 0;
}
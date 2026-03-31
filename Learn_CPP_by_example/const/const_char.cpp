#include <iostream>

using namespace std;


int main(void)
{
    char first_name[] = "George";
    char last_name[] = "Calin";

    char *p1 = first_name;

    cout<<"The value of p1 before the modification is ->"<<p1<<endl;
    cout<<"Print the memory address of p1"<<(void *) p1<<endl;

    p1[0] = 'W';
    cout<<"The value of p1 after the 1st modification is ->"<<p1<<endl;
    cout<<"The memory address where p1 is stored is "<<(void *) p1<<endl;

    //reassing where it points to
    p1 = last_name;
    cout<<"The value of p1 after the 2nd modification is ->"<<p1<<endl;
    cout<<"The memory address where p1 is stored is "<<(void *)p1<<endl;



    const char *p2 = first_name;

    cout<<"The value of p1 before the modification is ->"<<p2<<endl;
    cout<<"Print the memory address of p1"<<(void *) p2<<endl;

    //p2[0] = 'W'; //error on compilation

    /*
    expression must be a modifiable lvalueC/C++(137)
    const char *p2
    */

    cout<<"The value of p1 after the 1st modification is ->"<<p2<<endl;
    cout<<"The memory address where p1 is stored is "<<(void *) p2<<endl;


    char * const p3 = first_name;

    cout<<"The value of p1 before the modification is ->"<<p3<<endl;
    cout<<"Print the memory address of p1"<<(void *) p3<<endl;

    //reassing where it points to
    // p3 = last_name; // error on compilation
    /*
    expression must be a modifiable lvalueC/C++(137)
    char *const p3
    */
    cout<<"The value of p1 after the 2nd modification is ->"<<p3<<endl;
    cout<<"The memory address where p1 is stored is "<<(void *)p3<<endl;

    return 0;
}
#include <iostream>
using namespace std;


class Shape_Virtual
{
    public:
        virtual void print()
        {
            cout<<"SHAPE VIRTUAL: Inside print()"<<endl;
        }
};

class Shape_NonVirtual
{
    public:
        void print()
        {
            cout<<"SHAPE VIRTUAL: Inside print()"<<endl;
        }
};


class Circle_Virtual:public Shape_Virtual
{
    public:
        void print()
        {
            cout<<"CIRCLE VIRTUAL: Inside print()"<<endl;
        }
};


class Circle_NonVirtual:public Shape_NonVirtual
{
    public:
        void print()
        {
            cout<<"CIRCLE VIRTUAL: Inside print()"<<endl;
        }
};


int main(void)
{
   //objects instantiated on the stack , non pointers -> static binding of methods apply at compile time
    Shape_Virtual sv;
    Shape_NonVirtual snv;

    cout<<"Size of Shape_Virtual = "<<sizeof(sv)<<endl; // bigger size, a hidden member variable added by C++ vptr to store the correspondence to virtual table
    cout<<"Size of Shape_NonVirtual = "<<sizeof(snv)<<endl;

    sv.print(); //prints from Shape() * classes
    snv.print(); //prints from Shape() * classes

    Circle_Virtual cv;
    Circle_NonVirtual cnv;
    
    cout<<"Size of Circle_Virtual = "<<sizeof(cv)<<endl; // bigger size, it carries a hidden member variable from its parent/base class added by C++ vptr to store the correspondence to virtual table
    cout<<"Size of Circle_NonVirtual = "<<sizeof(cnv)<<endl;

    //static binding applies at compile time, cause the variables are on the stack, non-pointers
    cv.print(); //print() from Circle* classes
    cnv.print(); //print() from Circle* classes


    //pointer variables , which cause dynamic binding at runtime
    Shape_Virtual *svptr = new Circle_Virtual();
    svptr->print(); // print() is a virtual function in the base class, hence the print() from derived class is applied

    Shape_NonVirtual *snvptr = new Circle_NonVirtual();
    snvptr->print(); // print() is not a virtual function in the base class, hence the print() of the base class is applied


    //reference variables
    Shape_Virtual& svref = *svptr;
    svref.print(); // the print()  from the derived class runs

    Shape_NonVirtual& snvref = *snvptr;
    snvref.print(); // the print() from the base class applies

    return 0;
}
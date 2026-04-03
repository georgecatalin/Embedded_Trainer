#include <iostream>

using namespace std;


class Shape
{
    private:
    public:
        string shapeType;
        virtual void print()
        {
            cout<<"SHAPE: Hello from print()"<<endl;
        }
        Shape()
        {
            cout<<"SHAPE: I am inside the constructor"<<endl;
            print(); //rule: never use a virtual method in a constructor or destructor
        }
        ~Shape()
        {
            cout<<"SHAPE: I am inside the destructor"<<endl;
            print(); //rule: never use a virtual method in a constructor or destructor
        }

};

class Rectangle:public Shape
{
private:
    int length;
    int breadth;
public:
    Rectangle()
    {
        cout<<"RECTANGLE: i am inside the constructor"<<endl;
    }
    ~Rectangle()
    {
        cout<<"RECTANGLE: I am inside the destructor"<<endl;
    }
    void print()
    {
        cout<<"RECTANGLE: Hello print()"<<endl;
    }
};

int main(void)
{
   Rectangle r1; //r1 will be affected by the fact that virtual functions where used in constructor and destructor. the ones of shape will be statically dispatched, instead of one would expect, which is the derived class functions





    return 0;
}
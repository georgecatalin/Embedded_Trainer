#include <iostream>

using namespace std;

class Shape
{
private:
    string shapeType;

public:
    virtual void print()
    {
        cout << "SHAPE: print()" << endl;
    }
    Shape()
    {
        cout << "SHAPE: Inside the shape constructor" << endl;
        print(); // bad design one ought not not use virtual functions in constructors
    }
    ~Shape()
    {
        cout << "SHAPE: Inside the shape destructor" << endl;
        print(); // bad design one ought not not use virtual functions in constructors
    }
};

class Shape_virtual_destructor
{
private:
    string shapeType;

public:
    virtual void print()
    {
        cout<<"SHAPEV print()"<<endl;
    }
    Shape_virtual_destructor()
    {
        cout << "SHAPEV: Inside the shape constructor" << endl;
        print(); // bad design one ought not not use virtual functions in constructors
    }
    virtual ~Shape_virtual_destructor()
    {
        cout << "SHAPEV: Inside the shape destructor" << endl;
        print(); // bad design one ought not not use virtual functions in constructors
    }
};

class Rectangle : public Shape
{
private:
    int length;
    int breadth;

public:
    Rectangle()
    {
        cout << "RECTANGLE: Inside the rectangle constructor" << endl;
    }
    ~Rectangle()
    {
        cout << "RECTANGLE: Inside the rectangle destructor" << endl;
    }
    void print()
    {
        cout << "RECTANGLE: print" << endl;
    }
};

class Rectangle_virtual_destructor : public Shape_virtual_destructor
{
private:
    int length;
    int breadth;

public:
    Rectangle_virtual_destructor()
    {
        cout << "RECTANGLE: Inside the rectangle constructor" << endl;
    }
    ~Rectangle_virtual_destructor()
    {
        cout << "RECTANGLE: Inside the rectangle destructor" << endl;
    }
    void print()
    {
        cout << "RECTANGLE: print" << endl;
    }
};

int main(void)
{
    Shape *s = new Rectangle();
    delete s; // only fires the destructor of the base class =>>MEMORY LEAK


    /*
    Things made simple:
     -s is a Shape*, but actually points to a Rectangle object on the heap. When you delete s, the compiler looks at the static type of the pointer (Shape*) 
    to decide which destructor to call. 
    - Since Shape::~Shape() is not virtual, it calls only Shape::~Shape() — Rectangle::~Rectangle() is never called.
    - This is undefined behavior and a memory leak: any resources Rectangle owns (heap memory, file handles, etc.) are never released.
    */

    Shape_virtual_destructor *sv = new Rectangle_virtual_destructor();
    delete sv; // both destructors for derived class and base class fired

    /*
    Things made simple:
    -Because ~Shape_virtual_destructor() is virtual, the compiler uses the vtable to dispatch the destructor call.
    -It sees the real runtime type is Rectangle_virtual_destructor, so it calls Rectangle_virtual_destructor::~Rectangle_virtual_destructor() first, 
    then Shape_virtual_destructor::~Shape_virtual_destructor() — in the correct order. 
    
    */

    return 0;
}
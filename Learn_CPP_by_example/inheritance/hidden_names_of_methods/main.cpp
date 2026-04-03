#include <iostream>
using namespace std;

/*
Hidden naming is a faux case of overloading : it looks like overloading a function which looks pretty similar, but unlike overloading a function is defined in the base class, whilst the second form is defined in the derived class
*/

class Shape
{
private:
    string shapeType;

public:
    virtual void print()
    {
        cout << "SHAPE: Print number " << endl;
    }

    Shape()
    {
        cout << "SHAPE:I am inside the constructor." << endl;
    }

    virtual ~Shape()
    {
        cout << "SHAPE: I am inside the destructor." << endl;
    }
};

class Rectangle : public Shape
{
private:
    int length;
    int breadth;

public:
    void print(int number) // even it looks like, it differs from the virtual function in the base, it is a completely different method
    {
        cout << "RECTANGLE: Print number " << number << endl;
    }
    Rectangle()
    {
        cout << "RECTANGLE: I am inside the constructor." << endl;
    }
    ~Rectangle()
    {
        cout << "RECTANGLE: I am inside the destructor." << endl;
    }
};

int main(void)
{
    Shape *shape = new Rectangle();
    shape->Shape::print();

    static_cast<Rectangle *>(shape)->print(1954);

    return 0;
}

/*
Note: the destructors are automatically called only for Stack allocated objects

Only for stack-allocated objects. new allocates on the heap, and heap memory is never automatically released — you own it and must delete it manually.


// Stack - destructor called automatically at end of scope
Rectangle r;
return 0; // ~Rectangle() and ~Shape() called here ✓

// Heap - YOU are responsible
Shape *shape = new Rectangle();
return 0; // nothing called, memory leaked ✗
delete shape; // must do this explicitly ✓

*/
#include <iostream>
using namespace std;


/*
if one redefines a non-virtual method of the base class in the derived class, strange (actually unexpected behaviour occurs)
*/

class Shape
{
    private:
        string shapeType;
    public:
        void print()
        {
            cout<<"SHAPE: Print number "<<endl;
        }

        Shape()
        {
            cout<<"SHAPE:I am inside the constructor."<<endl;
        }

        ~Shape()
        {
            cout<<"SHAPE: I am inside the destructor."<<endl;
        }
};

class Rectangle: public Shape
{
    private: 
        int length;
        int breadth;
    public:
        void print()
        {
            cout<<"RECTANGLE: Print number "<<endl;
        }
        Rectangle()
        {
            cout<<"RECTANGLE: I am inside the constructor."<<endl;
        }
        ~Rectangle()
        {
            cout<<"RECTANGLE: I am inside the destructor."<<endl;
        }

};

int main(void)
{
   Rectangle rectangle; //the rectangle object is created on the stack, so the destructor will be called automatically when the object goes out of scope, so we do not need to delete it explicitly
   rectangle.print(); // one would expect to print 'RECTANGLE: Print number' but it prints 'SHAPE: Print number' because the method is not virtual,  so it does not dynamically dispatch to the derived class method, but rather it statically binds to the base class method
   
   Shape *shape = &rectangle; // the shape pointer points to the rectangle object, so it can access the base class method, but it cannot access the derived class method because it is not virtual, so it statically binds to the base class method
   shape->print(); // one would expect to print 'RECTANGLE: Print number' but it prints 'SHAPE: Print number' because the method is not virtual,  so it does

   Rectangle *rectanglePtr = &rectangle; // the rectangle pointer points to the rectangle object, so it can access both the base class method and the derived class method, but it will statically bind to the derived class method because it is the most derived class, so it will print 'RECTANGLE: Print number'
   rectanglePtr->print(); // it will print 'RECTANGLE: Print number' because it statically binds to the derived class method because it is the most derived class, so it will print 'RECTANGLE: Print number'

   return 0;    
}
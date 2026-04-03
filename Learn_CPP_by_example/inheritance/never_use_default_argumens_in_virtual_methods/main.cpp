#include <iostream>
using namespace std;



class Shape
{
    private:
        string shapeType;
    public:
        virtual void print(int number=1978)
        {
            cout<<"SHAPE: Print number "<<number<<endl;
        }

        Shape()
        {
            cout<<"SHAPE:I am inside the constructor."<<endl;
        }

        virtual ~Shape()
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
        void print(int number = 2011)
        {
            cout<<"RECTANGLE: Print number "<<number<<endl;
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
   Shape *shape = new Rectangle();
   shape->print();// one would expect to print '2011' which is the default of rectangle, although it dynamically dispatches the method to Rectangle class, but with Base class default argument value

/*
At runtime:
SHAPE:I am inside the constructor.
RECTANGLE: I am inside the constructor.
RECTANGLE: Print number 1978
*/

    return 0;
}
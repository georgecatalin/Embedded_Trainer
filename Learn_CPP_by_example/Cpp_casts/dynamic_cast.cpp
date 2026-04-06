#include <iostream>
#include <string>

using namespace std;

class Shape
{
private:
public:
    string shapeType;
    Shape()
    {
        cout << "unknown shape" << endl;
        cout << "Inside the no-argument shape constructor." << endl;
    }

    virtual ~Shape()
    {
        cout << "Inside the shape destructor." << endl;
    }
};

class Rectangle : public Shape
{
private:
public:
    int length;
    int breadth;
    Rectangle()
    {
        cout << "Inside the no-argument rectangle constructor." << endl;
    }

    ~Rectangle()
    {
        cout << "Inside the rectangle destructor." << endl;
    }
};

int main(void)
{

    /*
    The only way of downcasting an object of a base class to a derived class is using a run time cast, that is dynamic cast.
    the dynamic cast throws an error for a reference type or a null in case of a pointer conversion which is unsuccessful.
    */

    Shape *shape = new Shape();
    Shape *shape1 = new Rectangle(); // this is the essence of polymorphism, done quite often

    // we cast the objects to a rectangle object

    Rectangle *rectangle = dynamic_cast<Rectangle *>(shape);

    if (!rectangle)
    {
        cout << "Shape is not a rectangle" << endl;
    }
    else
    {
        cout << "Shape was converted successfully to a rectangle." << endl;
    }

    Rectangle *rectangle1 = dynamic_cast<Rectangle *>(shape1);
    if (!rectangle1)
    {
        cout << "Shape is not a rectangle" << endl;
    }
    else
    {
        cout << "Shape was converted successfully to a rectangle." << endl;
    }


     Shape s1;
     cout<<"_____"<<endl;
     Rectangle r1;

     //Shape& s2 = dynamic_cast<Rectangle&>(s1);

    cout<<"The type of s1 object -->"<<typeid(s1).name()<<endl;
    cout<<"The type of the shape object -->"<<typeid(shape).name()<<endl; //The type of the shape object -->P5Shape
    cout<<"The type of the shape object it points to -->"<<typeid(*shape).name()<<endl; //The type of the shape object it points to -->5Shape

    return 0;
}
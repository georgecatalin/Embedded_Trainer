#include <iostream>

using namespace std;

class ComplexNumber
{
private:
    float real_part;
    float imaginary_part;

public:
    ComplexNumber()
    {
        cout << "No arguments constructor was called." << endl;
    }

    void set_members(float m1, float m2)
    {
        real_part = m1;
        imaginary_part = m2;
    }

    float get_real_part()
    {
        return real_part;
    }

    float get_imaginary_part()
    {
        return imaginary_part;
    }

    void print()
    {
        cout<<"real part is "<<real_part<<" and imaginary part is "<<imaginary_part<<endl;
    }
};

int main()
{
    ComplexNumber c;
    cout << "Hello, this is an example with a basic class in C++. " << endl;
    c.print();
    cout << endl;
    c.set_members(1978, 2011);
    c.print();

    cout << endl;

    return 0;
}
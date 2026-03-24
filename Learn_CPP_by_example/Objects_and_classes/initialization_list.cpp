#include <iostream>
#include <cstring>

using namespace std;


class ComplexNumber
{
    private:
        float real_part;
        float imaginary_part;
    public:
    ComplexNumber() : real_part(0.0), imaginary_part(0.0)
    {
        cout<<"No arguments constructor was called "<<endl;
    }

    ComplexNumber(double r, double c) : real_part(r), imaginary_part(c)
    {
        cout<<"2 arguments constructor was called "<<endl;
    }

    ComplexNumber(const ComplexNumber& obj): real_part(obj.real_part), imaginary_part(obj.imaginary_part)
    {
        cout<<"Copy constructor was called for object "<<real_part<<"+i"<<imaginary_part<<endl;
    }

    void print()
    {
        cout<<"The object is {"<<real_part<<"+i"<<imaginary_part<<" }"<<endl;
    }

    void set_real(float r)
    {
        real_part = r;
    }

    void set_imaginary(float i)
    {
        imaginary_part = i;
    }

    float get_float()
    {
        return real_part;
    }

    float get_imaginary()
    {
        return imaginary_part;
    }

    ~ComplexNumber()
    {
        cout<<"Destructor was called for object "<<real_part<<"+i"<<imaginary_part<<endl;
    }

};

int main(void)
{
    ComplexNumber c1;
    c1.print();

    ComplexNumber c2(14,47);
    c2.print();

    ComplexNumber c3 = c2;
    c3.print();

    ComplexNumber c4(c2);
    c4.print();

    cout<<"Completed execution of main function "<<endl;



    return 0;
}
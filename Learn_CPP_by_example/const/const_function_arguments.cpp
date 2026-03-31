#include <iostream>

using namespace std;


class ComplexNumber
{
    private:
        float real_part;
        float imaginary_part;
    public:
    ComplexNumber(): real_part(0), imaginary_part(0)
    {
        cout<<"no argument(0 argument constructor) called "<<endl;
    }

    ComplexNumber(float r, float i): real_part(r),imaginary_part(i)
    {
        cout<<"2 arguments constructor called "<<endl;
    }

    ComplexNumber(const ComplexNumber& rhs): real_part(rhs.real_part), imaginary_part(rhs.imaginary_part)
    {
        cout<<"Copy constructor called here"<<endl;
    }

    ~ComplexNumber()
    {
        cout<<"Destructor called for object {"<<real_part<<" , "<<imaginary_part<<"}"<<endl;
    }

    float get_real_part() const
    {
        return real_part;
    }

    void set_real_part(float r)
    {
        real_part = r;
    }

};

 void printCallByValue(ComplexNumber c)
    {
        cout<<"Inside printCallByValue"<<endl;
        cout<<"real part of the number ->"<<c.get_real_part()<<endl;
        c.set_real_part(5.56);
    }

    void printCallByReference(ComplexNumber& c)
    {
        cout<<"Inside printCallByReference"<<endl;
        cout<<"real part of the number ->"<<c.get_real_part()<<endl;
        c.set_real_part(5.56); //attempts to set real_part member variables, succeeds because there is non const ref as parameter object
    }

    void printCallByConstReference(const ComplexNumber& c)
    {
        cout<<"Inside printCallByConstReference"<<endl;
        cout<<"real part of the number ->"<<c.get_real_part()<<endl;  // set get_real_part() as const , even though it does not change anything to avoid error when compiling
        //c.set_real_part(5.56); //attempts to set real_part member variables, error fetched because there is  const ref as parameter object

        /*
        the object has type qualifiers that are not compatible with the member function "ComplexNumber::set_real_part"C/C++(1086)
            const_function_arguments.cpp(60, 9): object type is: const ComplexNumber
            const ComplexNumber &c
            A constant reference to a ComplexNumber object, passed as a read-only parameter to prevent modification of the original complex number value.
        */
    }



int main(void)
{
    ComplexNumber c(7.62,39);

    cout<<"The value of real_part before running printCallByValue "<<c.get_real_part()<<endl;
    printCallByValue(c);
    cout<<"The value of real_part after running printCallByValue "<<c.get_real_part()<<endl;

    cout<<"The value of real_part before running printCallByRefecence "<<c.get_real_part()<<endl;
    printCallByReference(c);
    cout<<"The value of real_part after running printCallByReference "<<c.get_real_part()<<endl;


    cout<<"The value of real_part before running printCallByConstReference "<<c.get_real_part()<<endl;
    printCallByConstReference(c);
    cout<<"The value of real_part after running printCallByConstReference "<<c.get_real_part()<<endl;


    return 0;
}
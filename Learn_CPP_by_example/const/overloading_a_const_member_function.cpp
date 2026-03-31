#include <iostream>

using namespace std;

class Student
{
    private:
        string full_name;
    public:
    Student(const char *name): full_name(name)
    {
        cout<<"one argument constructor called for student ->"<<full_name<<endl;
    }

    void print()  // non-const overloaded variant of print() method
    {
        cout<<"non-const overloaded variant of the method:/nthe object is Student( "<<full_name<<" )"<<endl;
        full_name = string("Mara Calin"); // error when compiling cause a const member function can not modify any member variable

     
    }

    void print()  const // const overloaded variant of print() method
    {
        cout<<"const overloaded variant of the method:/nthe object is Student( "<<full_name<<" )"<<endl;
    }

    ~Student()
    {
        cout<<"Destructor called here"<<endl;
    }
};

int main(void)
{
   const Student s1("George");
   Student s2("Mara");

   s1.print(); // by default, a constant object calls the const overloaded version of the print() method
   s2.print(); // by default, a non constant object call the non-const overloaded version of the print() method


    return 0;
}
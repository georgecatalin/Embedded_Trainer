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
  
   //Student& ref_s1 = s1; // error when compiling because by using ref_s1 one could change the object s1

   /*
   qualifiers dropped in binding reference of type "Student &" to initializer of type "const Student"C/C++(433)
    const Student s1
 
    A constant Student object named s1. Since it is declared as const, its member variables cannot be modified after initialization.
   */

   //one fixture, to allow creation of non-const references for const objects
   Student& ref_s2 = const_cast<Student&> (s1);

    return 0;
}
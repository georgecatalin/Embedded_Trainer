#include <iostream>

using namespace std;

class Student
{
    private:
        mutable string full_name;
    public:
    Student(const char *name): full_name(name)
    {
        cout<<"one argument constructor called for student ->"<<full_name<<endl;
    }

    void print() const //member functions are not allowed to change  member variables
    {
        cout<<"the object is Student( "<<full_name<<" )"<<endl;
        full_name = string("Mara Calin"); // even though print() is marked as a const member function, it can still modify mutable member variables as an exception

      
    }
};



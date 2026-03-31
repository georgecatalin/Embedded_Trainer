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

    void print() const //member functions are not allowed to change  member variables
    {
        cout<<"the object is Student( "<<full_name<<" )"<<endl;
        //full_name = string("Mara Calin"); // error when compiling cause a const member function can not modify any member variable

        /*
        const_member_functions.cpp(18, 19): operand types are: const std::string = std::string
        */ 
    }
};



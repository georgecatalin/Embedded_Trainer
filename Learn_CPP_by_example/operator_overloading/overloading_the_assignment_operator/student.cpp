#include "student.h"

Student::Student(): full_name("")
{
    cout<<"inside of the no argument constructor"<<endl;
}


//const_cast<char*> is a C++ cast that removes the const qualifier from a pointer or reference. 
//For example, if you have a const char* (pointer to constant data), const_cast<char*>(ptr) will convert it to a char* 
//(pointer to non-const data).
Student::Student(const char *name) : full_name(const_cast<char*>(name))
{
    cout<<"inside the 1-argument constructor"<<endl;
}

Student::Student(const Student& rhs) : full_name(rhs.full_name)
{
    cout<<"inside the copy constructor"<<endl;
}

Student::~Student()
{
    cout<<"inside the destructor of the object ("<<full_name<<")"<<endl;
}

Student& Student::operator=(const Student& rhs)
{
    cout<<"inside the operator = function overloader"<<endl;
    if(this != &rhs) // verify to not assign to itself because at the next step we are going the deallocate the memory
    {

        if(rhs.full_name != NULL)
        {
            full_name = new char[50]; //allocate memory again to store the full_name
            strcpy(full_name,rhs.full_name); //copy from right hand operator, to object
        }
    }
    return *this;
}

void Student::print() const
{
    cout<<"object is ("<<full_name<<")"<<endl;
}
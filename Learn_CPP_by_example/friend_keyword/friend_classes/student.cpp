#include "student.h"

Student::Student() : fullname("")
{
    cout << "inside the no-argument constructor" << endl;
}

Student::Student(const char *name) : fullname(name)
{
    cout << "object initialized with ->" << fullname << endl;
}

Student::Student(const Student &s) : fullname(s.fullname)
{
    cout << "Inside the copy constructor" << endl;
}

Student::~Student()
{
    cout << "Inside the destructor" << endl;
}
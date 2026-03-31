#ifndef _STUDENT_H
#define _STUDENT_H

#include <iostream>

using namespace std;

class Student
{
    private:
        string fullname;
    public:
    Student();
    Student(const char *name);
    Student(const Student& s);
    ~Student();

    friend class School; //by marking the class School as friend, all its member functions will become friend functions, thus they will see the private member variables of this function
};

#endif
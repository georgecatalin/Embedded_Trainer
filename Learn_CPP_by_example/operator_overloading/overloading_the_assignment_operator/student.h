#ifndef _STUDENT_H
#define _STUDENT_H

#include <iostream>
#include <cstring>

using namespace std;

class Student
{
    private:
        char *full_name;
    public:
        Student();
        Student(const char *name);
        Student(const Student& rhs);

        ~Student();
        Student& operator=(const Student& rhs);
        void print() const;

        /*
        Theory:
        1. the assignment operator is very often used with primitive types, and user defined types alike
        2. user defined types make use by default by the C++ assignment implementation for the operator, which  for (a=b) moves the content of the memory from b to the location of memory a

        return types:

        void operator=(const Student& rhs) => if we did this, a=b=c would not work
        const Student& operator=(const Student& rhs) => if we did this (a=b) = c  operation would not work
        
        
        */
};



#endif
#include "school.h"


School::School(): id(0)
{
    cout<<"inside the no-arguments constructor"<<endl;
}

School::School(int id) : id(id)
{
    cout<<"object initialized with id="<<id<<endl;
}

School::School(const School& rhs): id(rhs.id)
{
    cout<<"inside the copy constructor "<<endl;
}

School::~School()
{
    cout<<"inside the destructor"<<endl;
}

void School::admitStudent(const Student& student)
{
    cout<<"The student was admitted ->"<<student.fullname<<endl;
}

void School::expelStudent(const Student& student)
{
    cout<<"The student was expelled ->"<<student.fullname<<endl;
}
#include "person.h"

Person::Person()
{
    cout<<"I am in the no-argument constructor."<<endl;
}

Person::Person(string name): name(name)
{
    cout<<"I am in the 1-argument constructor."<<endl;
} 

Person::~Person()
{
    cout<<"I am inside the destructor."<<endl;
}

string Person::getName()
{
    return name;
}
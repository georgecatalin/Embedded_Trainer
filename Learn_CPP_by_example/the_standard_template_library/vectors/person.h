#ifndef _PERSON_H
#define _PERSON_H

#include <iostream>
using namespace std;


class Person
{
    private:    
        string name;
    public:
        Person();
        Person(string name);
        ~Person();
        string getName();
};





#endif //_PERSON_H  
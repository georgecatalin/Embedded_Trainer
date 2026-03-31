#ifndef _SCHOOL_H
#define _SCHOOL_H

#include <iostream>
#include "student.h"  //one needs to add this, cause forward declaration is not sufficient. no info about private members inferred only through forward declaration

using namespace std;

class School
{
  private:
    int id;
  public:
    School();
    School(int i);
    School(const School& rhs);

    void admitStudent(const Student& s);
    void expelStudent(const Student& s);

    ~School();
};

#endif
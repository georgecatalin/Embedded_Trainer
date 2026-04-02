#include "circle.h"

void Circle::print()
{
    cout<<"CIRCLE: I am a circle"<<endl;
}

//NOTE: in the derived class, if one does not implement all pure virtual functions from the base class, then the derived class remains abstract and can not be instantiated
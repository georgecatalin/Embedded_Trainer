#include "shape.h"
#include "square.h"
#include "rectangle.h"
#include "rhombus.h"


int main(void)
{
    Square s;

    //How to specify which method to run in a diamond hierarchy, since two objects of the grandfather are available at once
    s.Rectangle::print(); // 
    s.Rhombus::print();


    return 0;
}
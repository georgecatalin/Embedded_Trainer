#include "shape.h"
#include "circle.h"

int main(void)
{
   Shape *sptr = new Circle("shape A", 5.56);
   sptr->print();





    return 0;
}
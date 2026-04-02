#include "shape.h"
#include "circle.h"

int main(void)
{
    //Shape_Abstract shape; //object is not allowed-> abstract class

    Shape_Abstract *shape = new Circle();
    shape->print(); // because print() is a virtual function in the base, the implementation of the print() method runs here which is a manifestation of runtime polimorphism

    



    return 0;
}
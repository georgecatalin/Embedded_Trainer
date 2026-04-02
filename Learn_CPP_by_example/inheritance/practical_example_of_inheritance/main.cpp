#include "shape.h"
#include "circle.h"

int main(void)
{
    cout<<"start of the program"<<endl;
    cout<<"create instance c1 of Circle()"<<endl;
    Circle c1("shape type A", 5.56);

    cout<<"create instance c2 of Circle()"<<endl;
    Circle c2("shape type B", 7.62);

    cout<<"create instance c3 of Circle()"<<endl;
    Circle c3 = c1;


    cout<<"end of the program"<<endl;

    return 0;
}
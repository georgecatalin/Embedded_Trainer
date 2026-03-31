#include "static_member_functions.h"

int ComplexNumber::numberObjectsCreated = 0;
 
ComplexNumber::ComplexNumber(): realPart(0), imaginaryPart(0)
{
    cout<<"no argument constructor was called"<<endl;
    numberObjectsCreated++;
}

ComplexNumber::ComplexNumber(float r, float i): realPart(r), imaginaryPart(i)
{
    cout<<"2 argument constructor was called"<<endl;
    numberObjectsCreated++;
}

ComplexNumber::ComplexNumber(const ComplexNumber& rhs): realPart(rhs.realPart), imaginaryPart(rhs.imaginaryPart)
{
    cout<<"copy constructor was called"<<endl;
    numberObjectsCreated++;
}

int ComplexNumber::getNumberObjectsCreated()
{
    cout<<"inside the function() -->  getNumberObjectsCreated() "<<endl;
    return numberObjectsCreated;
}


ComplexNumber::~ComplexNumber()
{
    cout<<"Destructor was called"<<endl;
}




int main(void)
{
   cout<<"Number of objects existing before creating any object ->>"<<ComplexNumber::getNumberObjectsCreated()<<endl;
   ComplexNumber c1;
   cout<<"Number of objects existing after creating an object ->>"<<ComplexNumber::getNumberObjectsCreated()<<endl;

   cout<<"Number of objects existing before creating the 2nd object ->>"<<ComplexNumber::getNumberObjectsCreated()<<endl;
   ComplexNumber c2(7.62,39);
   cout<<"Number of objects existing after creating the 2nd object ->>"<<ComplexNumber::getNumberObjectsCreated()<<endl;

   cout<<"Number of objects existing before creating the 3rd object ->>"<<ComplexNumber::getNumberObjectsCreated()<<endl;
   ComplexNumber c3(5.56,45);
   cout<<"Number of objects existing after creating the 3rd object ->>"<<ComplexNumber::getNumberObjectsCreated()<<endl;

    return 0;
}
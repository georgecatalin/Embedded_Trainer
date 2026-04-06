#include <iterator>
#include "person.h"
#include <vector>

int main(void)
{
   size_t size = 3;
   vector<Person> family(size);

   family[0] = Person("Mara");
   family[1] = Person("Zizou");
   family[2] = Person("Milla");

   vector<Person>::iterator my_iterator;

   for(my_iterator=family.begin(); my_iterator!=family.end();my_iterator++)
   {
    cout<<"Element is "<<my_iterator->getName()<<endl;
    cout<<"Element is "<<(*my_iterator).getName()<<endl;
   }

   //the iterators are smart pointers at their origin

   //how to delete a vector using iterators
   family.erase(family.begin(),family.end());

   for(my_iterator=family.begin(); my_iterator!=family.end();my_iterator++)
   {
    cout<<"The element is "<<my_iterator->getName()<<endl;
    cout<<"The element is "<<(*my_iterator).getName()<<endl;
   }



    return 0;
}
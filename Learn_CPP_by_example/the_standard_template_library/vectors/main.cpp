#include <iostream>
#include <vector>
#include <string>
#include "person.h"

int main(void)
{
    size_t size = 4;

    vector<string> myList(size);

   myList[0] = "George";
   myList[1] = "Mara";
   myList[2] = "Zizou";
   myList[3] = "Sorina";


   cout<<"The capacity of the vector is ->"<<myList.capacity()<<endl;
   cout<<"The size of the vector is ->"<<myList.size()<<endl;

   myList.push_back("Milla"); //add a new element on top of all

   //print all elements in the vector
   for (size_t i = 0; i < myList.size(); i++)
   {
    cout<<"Element #"<<i<<" is "<<myList[i]<<endl;
   }
   

   vector<Person> listPersons(size);
   listPersons[0] = Person("George");
   listPersons[1] = Person("Mara");
   listPersons[2] = Person("Zizou");
   listPersons[3] = Person("Milla");

   cout<<"the capacity is "<<listPersons.capacity()<<endl;
   cout<<"The size is "<<listPersons.size()<<endl;

   listPersons.push_back(Person("Sorina"));

   for (size_t i = 0; i < listPersons.size(); i++)
   {
     cout<<"Element "<<i<<" is "<<listPersons[i].getName()<<endl;
   }
   


    return 0;
}

/*
- **`size()`** — the number of elements currently stored in the vector.
- **`capacity()`** — the number of elements the vector can hold before it needs to allocate more memory.

In your code, after `vector<string> myList(size)` with `size = 4`:
- `size()` = 4 (four actual elements)
- `capacity()` = 4 (allocated space for exactly 4)

After `myList.push_back("Milla")`:
- `size()` = 5 (five elements now)
- `capacity()` = 8 (the vector doubled its allocation to avoid frequent reallocations)

The capacity grows faster than the size — typically doubling — so that repeated `push_back` calls are amortized O(1) rather than reallocating on every insert.

*/
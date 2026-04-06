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
   

    return 0;
}
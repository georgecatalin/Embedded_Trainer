#include <iostream>

using namespace std;


int main(void)
{
    const int age = 47;
    age++; //error to be fetched

    const string first_name("George");
    first_name.insert(0,"Calin "); //error to be fetched


    /*
    basic_use.cpp(12, 16): argument types are: (int, const char [7])
basic_use.cpp(12, 16): object type is: const std::string
    */

    return 0;
}
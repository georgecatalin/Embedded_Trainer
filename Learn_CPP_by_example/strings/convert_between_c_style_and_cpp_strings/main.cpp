#include <iostream>
#include <string>
#include <cstring>

using namespace std;

int main(void)
{
    string my_name = "George Calin"; //C++ style string

    char *c_string = new char[my_name.length()+1]; //c_string is old fashion C style string
    strcpy(c_string,my_name.c_str());

    
    string new_cpp_style_string_again(c_string);


    cout<<"First situation, brand new C++ string style "<<my_name<<endl;
    cout<<"Second situation, C like string converted "<<c_string<<endl;
    cout<<"Third situation, C++ style string reconverted back " <<new_cpp_style_string_again<<endl;

    delete[] c_string;



    return 0;
}
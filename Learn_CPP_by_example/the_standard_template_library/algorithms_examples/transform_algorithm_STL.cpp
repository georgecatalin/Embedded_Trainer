#include <string>
#include <iostream>
#include <iterator>
#include <algorithm>

using namespace std;

int main(void)
{
    string fullName = "George Calin";
    cout << "My name before using 'transform' algorithm STL object is ->" << fullName << endl << endl;

    transform(fullName.begin(), fullName.end(),fullName.begin(),::toupper);

    cout<<"My name after using 'transform' algorithm STL object is ->"<<fullName<<endl<<endl;


    return 0;
}

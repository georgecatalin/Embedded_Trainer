#include <iostream>
#include <string>
#include <vector>
#include <iterator>
#include <algorithm>

using namespace std;

int main(void)
{
    vector<string> militaryAircraft;

    militaryAircraft.push_back("F-22 Raptor");
    militaryAircraft.push_back("F-35 Lightning II");
    militaryAircraft.push_back("J-20 Mighty Dragon");
    militaryAircraft.push_back("Su-57 Felon");
    militaryAircraft.push_back("Eurofighter Typhoon");
    militaryAircraft.push_back("Dassault Rafale");
    militaryAircraft.push_back("F-15EX Eagle II");

    // algorithms look like functions, but they are objects of classes in STL
    vector<string>::iterator findIT = find(militaryAircraft.begin(), militaryAircraft.end(), "Su-57 Felon");

    cout << "Searching for elements inside the vector using algorithms, which are special type of objects." << endl;

    if (findIT == militaryAircraft.end())
    {
        cout << " I did not find the element you are searching for " << endl;
    }
    else
    {
        cout<<" I find the element at the position "<<findIT - militaryAircraft.begin()<<endl;
    }

    return 0;
}
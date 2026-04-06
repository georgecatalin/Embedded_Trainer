#include <iostream>
#include <vector>
#include <iterator>
#include <map>
#include <string>

using namespace std;

int main(void)
{
    map<string, string> students;

    // elements in a map can be added in two manners, one with the insert() method, and the other way, with the simpler key,value pair
    students.insert(pair<string, string>("George", "Calin"));
    students.insert(pair<string, string>("Mara", "Calinovici"));
    students.insert(pair<string, string>("Sorina", "Calinescu"));

    students["Zizou"] = "Catelun";

    // search in a map is very fast
    if (students.find("Maras") == students.end())
    {
        cout << "I could not find the student Maras" << endl;
    }

    if (students.find("Mara") == students.end())
    {
        cout << "I could not find the student Mara" << endl;
    }
    else
    {
        cout<<"Mara is in the list"<<endl;
    }

//how to use iterators with maps

vector<string> firstName;
vector<string> lastName;

map<string,string>::iterator my_iterator;

for(my_iterator=students.begin(); my_iterator!=students.end();my_iterator++)
{
    firstName.push_back(my_iterator->first);
    cout<<"in the iterator -> "<<my_iterator->first<<endl;

    lastName.push_back(my_iterator->second);
    cout<<"in the iterator -> "<<my_iterator->second<<endl;
}


vector<string>::iterator vectorIterator;
for(vectorIterator=firstName.begin();vectorIterator!=firstName.end();vectorIterator++)
{
    cout<<"ELEMENT "<<*vectorIterator<<endl;
}

vector<string>::iterator vectorIterator2;
for(vectorIterator2=lastName.begin();vectorIterator2!=lastName.end();vectorIterator2++)
{
    cout<<"ELEMENT "<<*vectorIterator2<<endl;
}
    return 0;
}
// this is also called template specialization for a class

#include <iostream>
#include <string>

using namespace std;

template <class KeyType, class ValueType>
class KeyValuePair
{
private:
    KeyType key;
    ValueType value;

public:
    KeyValuePair(KeyType k, ValueType v) : key(k), value(v)
    {
        cout << "I am inside the class template (no specialization) for a given class " << endl;
    }

    KeyType getType() const
    {
        return key;
    }

    ValueType getValue() const
    {
        return value;
    }
};

/*
there are two types of specialization:
1. total class specialization when both parameters are specialized
2. partial class specialization when only one parameter is specialized, the other is known
*/

// total specialization of the class template
template <>
class KeyValuePair<string, string>
{   
private:
    string key;
    string value;

public:
    KeyValuePair(string k, string v) : key(k), value(v)
    {
        cout << "Inside the total specialization of the class." << endl;
    }
    string getKey() const
    {
        return key;
    }
    string getValue() const
    {
        return value;
    }
};

// partial specialization of the template class, only one data type of the arguments is unknown. the other is known
template <class KeyType>
class KeyValuePair<KeyType, int>
{
private:
    KeyType key;
    int value;

public:
    KeyValuePair(KeyType k, int v) : key(k), value(v)
    {
        cout << "Inside the partial specialization of the class." << endl;
    }
    KeyType getKey() const
    {
        return key;
    }
    int getValue() const
    {
        return value;
    }
};

int main(void)
{
    //the class is obtained from the template only when the class is instantiated. Compiler checks for the template for that particular type
    KeyValuePair<float,float> object1(5.56,7.62);
    KeyValuePair<string,string> object2("George","Calin");
    KeyValuePair<string,int> object3("George",1978);


    return 0;
}
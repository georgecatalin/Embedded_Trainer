#include <iostream>
using namespace std;



template<class T>
int smartCompare(const T& a, const T& b)
{
    if(a>b)
    { 
        return 1;
    }
    else if(a<b)
    {
        return -1;
    }
    else
    {
        return 0;
    }
}

//explicit overriding of template function for string data type
int smartCompare(const string& a, const string& b)
{
    cout<<"I override the template function for string data type."<<endl;
    return 0;
}


int main(void)
{
   int a = 1978;
   int b = 2011;

   int result = smartCompare(a,b);
   cout<<"First template specification: "<<result<<endl;


   string g{"George"};
   string m{"Mara"};
   
    int result_strings = smartCompare(g,m);
    

    return 0;
}
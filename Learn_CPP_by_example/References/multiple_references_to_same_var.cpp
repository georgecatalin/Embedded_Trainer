#include <iostream>

using namespace std;


int main(void)
{
  int x = 1953;

  int& y = x;
  int& z = x;

  cout<<" x="<<x<<" y="<<y<<" z="<<z<<endl; //1953 1953 1953

  y = 2011;
  cout<<" x="<<x<<" y="<<y<<" z="<<z<<endl; // 2011 2011 2011

  y = 1977;
  cout<<" x="<<x<<" y="<<y<<" z="<<z<<endl; //1977 1977 1977



    return 0;
}
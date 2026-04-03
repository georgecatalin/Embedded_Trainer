#include <iostream>

using namespace std;

namespace george
{
    template <class T>
    void swap(T &a, T &b)
    {
        T temporary = a;
        a = b;
        b = temporary;
    }
}

int main(void)
{
    int a = 1978;
    int b = 1954;

    cout << "a = " << a << " b = " << b << endl;

    george::swap(a, b); // at compile time, compiler checks if it has a definition for such function with ints, if not it looks for a template from which it can specialize the function

    cout << "a = " << a << " b = " << b << endl;

    string g("George");
    string m("Mara");

    cout << "g = " << g << " m = " << m << endl;

    george::swap(g, m);

    cout << "g = " << g << " m = " << m << endl;

    return 0;
}
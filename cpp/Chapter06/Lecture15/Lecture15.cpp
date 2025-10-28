/*
    참조와 const
*/
#include <iostream>

using namespace std;

void doSomething(const int& x) // unlike pointers, won't copy the variable
{
    cout << x << endl;
}

int main()
{
    int x = 5;
    const int& ref_x = x;

    const int& ref = 3 + 4;

    cout << ref << endl;
    cout << &ref << endl;

    // then what's the difference from just const int?
    int a = 1;

    doSomething(a);
    doSomething(1); // const int& can reference temporary objects (int& can't)
    doSomething(a + 3);

    return 0;
}
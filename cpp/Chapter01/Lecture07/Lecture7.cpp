/*
    지역 범위 Local Scope
*/
#include <iostream>

using namespace std;

void doSomething(int x)
{
    x = 123;
    cout << x << endl;
}

int main()
{
    /*int x(0);
    cout << x << " " << &x << endl;

    {
        int x(1);
        cout << x << " " << &x << endl;
    }

    cout << x << " " << &x << endl;*/

    int x = 0;

    cout << x << endl;
    doSomething(x);
    cout << x << endl;

    return 0;
}
/*
    증가/감소 연산자 Increment Decrement
*/
#include <iostream>

using namespace std;

int add(int a, int b)
{
    return a + b;
}

int main()
{
    int x = 6, y = 6;

    cout << x << " " << y << endl;
    cout << ++x << " " << --y << endl;
    cout << x++ << " " << y-- << endl;
    cout << x << " " << y << endl;

    // do not use
    int v = add(x, ++x);    
    cout << v << endl;

    x = x++;

    return 0;
}
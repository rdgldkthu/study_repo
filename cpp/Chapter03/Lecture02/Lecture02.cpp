/*
    산술 연산자 Arithmetic Operators
*/
#include <iostream>

using namespace std;

int main()
{
    int x = 7;
    int y = 4;
    int z = x % y;

    cout << "x : " << x << endl;
    cout << "y : " << y << endl;
    cout << "z : " << z << endl;

    cout << x / y << endl;
    cout << x / float(y) << endl;
    cout << float(x) / y << endl;
    cout << float(x) / float(y) << endl;

    cout << -5 / 2 << endl;

    return 0;
}
/*
    논리 연산자 Logical Operators
*/
#include <iostream>
#include <cmath>

int main()
{
    using namespace std;

    //bool x = true;
    //bool y = false;
    //
    //// logical NOT
    //cout << (!x) << endl;

    //// logical AND
    //cout << (x && y) << endl;

    //// logical OR
    //cout << (x || y) << endl;

    //// not equal : x != y

    //// short circuit evaluation
    int x = 2;
    int y = 2;

    if ((x == 1) && (y++ == 2)) // < y++ will not be executed if x == 1 is false
    {
        // do something
    }
    cout << y << endl;

    return 0;
}
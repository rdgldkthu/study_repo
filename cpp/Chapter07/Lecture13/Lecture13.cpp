/*
    방어적 프로그래밍의 개념 Defensive Programming
*/
#include <iostream>

using namespace std;

int main()
{
    // syntax errors
    //int x

    // semantic errors
    //if (x >= 5)
    //    cout << "x is greater than 5" << endl;

    // violated assumption
    string hello = "Hello, my name is Jack Jack";

    cout << "Input from 0 to " << hello.size() - 1 << ":";

    while (true)
    {
        int ix;
        cin >> ix; // cannot be greater than string length

        if (ix >= 0 && ix <= hello.size() - 1)
        {
            cout << hello[ix] << endl;
            break;
        }
        else
            cout << "Please try again" << endl;
    }

    return 0;
}
/*
    불리언 boolean
    조건문 if statements
*/
#include <iostream>

bool isEqual(int a, int b)
{
    bool result = (a == b);
    return result;
}

int main()
{
    using namespace std;

    /*bool b1 = true;
    bool b2(false);
    bool b3{ true };
    b3 = false;

    cout << std::boolalpha;
    cout << b3 << endl;
    cout << !b1 << endl;

    cout << (true && true) << endl;
    cout << (true || false) << endl;

    if (true)
    {
        cout << "This is true" << endl;
    }
    else
    {
        cout << "This is false" << endl;
    }*/

    /*cout << std::boolalpha;
    cout << isEqual(1, 1) << endl;
    cout << isEqual(1, 5) << endl;*/

    bool b;
    cin >> b;
    cout << std::boolalpha;
    cout << "Your input : " << b << endl;

    return 0;
}
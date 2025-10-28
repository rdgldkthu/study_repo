/*
    반복문 for
*/
#include <iostream>

int pow(int base, int exponent)
{
    int result = 1;

    for (int count = 0; count < exponent; count++)
    {
        result *= base;
    }

    return result;
}

int main()
{
    using namespace std;

    int count = 0;

    for (; count < 10; count++)
    {
        cout << count << endl;
    }

    cout << count << endl;

    cout << pow(2, 5) << endl;

    for (int i = 0, j = 9; i < 10; i++, j--)
    {
        cout << i << " " << j << endl;
    }

    return 0;
}
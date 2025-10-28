/*
    정수형 integer
    char vs int
    -> char : 1 byte, int : minimum 2 bytes usually 4 bytes
    signed vs unsigned
    overflow
*/
#include <iostream>
#include <cmath>
#include <limits>

using namespace std;

int main()
{
    /*cout << sizeof(short) << endl;
    cout << sizeof(int) << endl;
    cout << sizeof(long) << endl;
    cout << sizeof(long long) << endl;*/

    short       s = 1;  // 2 bytes = 2 * 8 bits = 16 bits
    int         i = 1;
    long        l = 1;
    long long   ll = 1;

    /*cout << pow(2, sizeof(short) * 8 - 1) - 1 << endl;
    cout << numeric_limits<short>::max() << endl;
    cout << numeric_limits<short>::min() << endl;
    cout << numeric_limits<short>::lowest() << endl;*/

    s = numeric_limits<short>::min();
    s -= 1;

    cout << s << endl;  // overflow

    return 0;
}
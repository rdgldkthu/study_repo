/*
    비트단위 연산자 Bitwise Operators
*/
#include <iostream>
#include <bitset>

int main()
{
    using namespace std;

    // << left shift
    // >> right shift
    // ~, &, |, ^

    unsigned int a = 1024;

    cout << std::bitset<16>(a) << endl;

    unsigned int b = a >> 3;

    cout << std::bitset<16>(b) << " " << b << endl;

    int x = 0b1100;
    int y = 0b0110;

    cout << std::bitset<4>(x & y) << endl;
    cout << std::bitset<4>(x | y) << endl;
    cout << std::bitset<4>(x ^ y) << endl;

    return 0;
}
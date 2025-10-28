/*
    리터럴 상수 literal constants
*/
#include <iostream>

int main()
{
    using namespace std;

    // Decimal  : 0 1 2 3 4 5 6 7 8 9 10 11 
    // Octal    : 0 1 2 3 4 5 6 7 10 11 12
    int x = 012;
    cout << x << endl;
    // Hexa     : 0 1 2 3 4 5 6 7 8 9 A B C D E F 10
    int y = 0xF;
    cout << y << endl;
    // Binary
    int z = 0b0000'0001'1010;   // ' for convenience
    cout << z << endl;

    return 0;
}
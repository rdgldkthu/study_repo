/*
    연산자 Operators
    리터럴 Literal
    피연산자 Operand
    단항 unary
    이항 binary
    삼항 ternary
*/
#include <iostream>

using namespace std;

int main()
{
    int x = 2;  // x is a variable, 2 is a literal

    cout << -x << endl; // unary

    cout << x + 2 << endl;  // binary

    int y = (x > 0) ? 1 : 2;    //ternary

    cout << y << endl;

    cout << "My Home" << endl;

    return 0;
}
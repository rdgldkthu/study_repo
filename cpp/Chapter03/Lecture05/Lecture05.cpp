/*
    관계 연산자 Relational Operators
*/
#include <iostream>
#include <cmath>

int main()
{
    using namespace std;

    /*int x, y;
    cin >> x >> y;
    cout << "Your input values are: " << x << " " << y << endl;

    if (x == y)
        cout << "equal" << endl;
    if (x != y)
        cout << "not equal" << endl;
    if (x > y)
        cout << "x is greater than y" << endl;
    if (x < y)
        cout << "x is less than y" << endl;
    if (x >= y)
        cout << "x is greater than or equal to y" << endl;
    if (x <= y)
        cout << "x is less than or equal to y" << endl;*/

    double d1(100 - 99.99);
    double d2(10 - 9.9);

    const double epsilon = 1e-10;

    if (std::abs(d1 - d2) < epsilon)
        cout << "approximately equal" << endl;
    else
        cout << "not equal" << endl;
    return 0;
}
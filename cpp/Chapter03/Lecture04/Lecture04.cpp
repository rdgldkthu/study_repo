/*
    sizeof, 쉼표 연산자 Comma Operator, 조건부 연산자 Conditional Operator
*/
#include <iostream>

int main()
{
    using namespace std;

    float a;

    sizeof(float);

    // comma operator

    int x = 3;
    int y = 10;
    //int z = (++x, ++y);
    ++x;
    ++y;
    int z = y;

    cout << x << " " << y << " " << z << endl;

    //int a = 1, b = 10;
    //int z;
    //z = a, b;   // (z = a), b;

    // conditional operator

    bool onSale = true;

    const int price = onSale ? 10 : 100;

    cout << price << endl;
    
    return 0;
}
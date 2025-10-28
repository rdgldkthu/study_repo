/*
    함수 템플릿 Templates
*/
#include <iostream>
#include "Cents.h"

using namespace std;

template<typename T>
T getMax(T x, T y)
{
    return (x > y) ? x : y;
}

int main()
{
    cout << getMax(1, 3) << endl;
    cout << getMax(1.0, 2.0) << endl;
    cout << getMax(3.14f, 2.0f) << endl;
    cout << getMax('a', 'c') << endl;

    cout << getMax(Cents(5), Cents(9)) << endl;

    return 0;
}
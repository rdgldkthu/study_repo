/*
    심볼릭 상수 symbolic constants
*/
#include <iostream>
#include "MY_CONSTANTS.h"

using namespace std;

void printNumber(const int my_number) // parameter가 함수 내에서 바뀌는 것을 막기 위해 자주 사용
{
    int n = my_number;
    cout << n << endl;
}

int main()
{
    constexpr int mass(5);    // compile time

    int number;
    cin >> number;

    const int special_number(number);   // run time

    double gravitational_force = mass * constants::gravity;

    return 0;
}
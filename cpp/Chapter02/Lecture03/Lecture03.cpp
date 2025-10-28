/*
    고정 너비 정수 fixed-width integers
    > c++11
*/
#include <iostream>
// #include <cstdint>

int main()
{
    std::int16_t i(5);
    std::int8_t myint = 65;

    std::cout << myint << std::endl;

    std::int_fast8_t fi(5);
    std::int_least64_t fl(5);
    return 0;
}
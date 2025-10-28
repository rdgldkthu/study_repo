/*
    포인터와 const
*/
#include <iostream>

using namespace std;

int main()
{
    // const int should be pointed by const pointer
    const int value = 5;
    const int* ptr = &value;
    //*ptr = 6;

    // cannot reassign by dereferencing, but can change the original variable
    int value1 = 5;
    const int* ptr1 = &value1;
    //*ptr1 = 6;
    value1 = 6;

    cout << *ptr1 << endl;
    
    // const is the data not the pointer itself
    int value2 = 5;
    const int* ptr2 = &value2;
    //*ptr2 = 7;

    int value3 = 6;
    ptr = &value3;

    // real const pointer
    int value4 = 5;
    int* const ptr4 = &value4;

    // both dereferenced data and the pointer are consts
    const int* const ptr5 = &value4;

    return 0;
}
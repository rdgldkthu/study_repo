/*
    자료형이 아닌 템플릿 매개변수 Non-type Parameters
*/
#include <iostream>
#include "MyArray.h"

using namespace std;

int main()
{
    MyArray<double, 100> my_array; //std::array<double, 100>

    for (int i = 0; i < my_array.getLength(); i++)
        my_array[i] = i + 65;

    my_array.print();

    return 0;
}
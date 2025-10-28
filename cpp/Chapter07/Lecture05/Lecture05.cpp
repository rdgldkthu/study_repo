/*
    다양한 반환 값들 Returning Values (값, 참조, 주소, 구조체, 튜플)
*/
#include <iostream>
#include <array>
#include <tuple>

using namespace std;

std::tuple<int, double> getTuple()
{
    int a = 10;
    double d = 3.14;
    return std::make_tuple(a, d);
}

//int* getValue(int x) // not recommended return temporary address
//{
//    int value = x * 2;
//    return &value;
//}

//int* allocateMemory(int size)
//{
//    return new int[size];
//}

//int& getValue(int x)
//{
//    int value = x * 2;
//    return value;
//}

//int& get(std::array<int, 100>& arr, int idx)
//{
//    return arr[idx];
//}

//struct S
//{
//    int a, b, c, d;
//};
//
//S getStruct()
//{
//    S my_s{ 1, 2, 3 ,4 };
//}

int main()
{
    /*int* arr = allocateMemory(1024);
    delete[] arr;*/

    /*int &value = getValue(5);

    cout << value << endl;
    cout << value << endl;*/

    /*std::array<int, 100> my_array;
    my_array[30] = 10;

    get(my_array, 30) *= 10;

    cout << my_array[30] << endl;*/

    /*S my_s = getStruct();
    my_s.b;*/

    /*std::tuple<int, double> my_tp = getTuple();
    cout << std::get<0>(my_tp) << endl;
    cout << std::get<1>(my_tp) << endl;*/

    /*auto [a, d] = getTuple();     // C++17
    cout << a << endl;
    cout << d << endl;*/

    return 0;
}
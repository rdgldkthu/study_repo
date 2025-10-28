/*
     함수 포인터 Function Pointers
*/
#include <iostream>
#include <array>
#include <functional>

using namespace std;

int func(int x)
{
    return 5;
}

bool isEven(const int& number)
{
    if (number % 2 == 0) return true;
    else return false;
}

bool isOdd(const int& number)
{
    if (number % 2 != 0) return true;
    else return false;
}

//typedef bool (*check_fcn_t)(const int&);
using check_fcn_t = bool(*)(const int&);

//void printArray(const array<int, 10>& arr, check_fcn_t check_fcn = isEven)
void printArray(const array<int, 10>& arr, std::function<bool(const int&)> check_fcn = isEven)
{
    for (auto& element : arr)
    {
        if (check_fcn(element)) cout << element;
    }
    cout << endl;
}


int main()
{
    //cout << func << endl; // functions are pointers
    
    /*int(*fcnptr)(int) = func;
    cout << fcnptr() << endl;*/

    std::array<int, 10> my_array{ 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };

    std::function<bool(const int&)> fcnptr = isEven;

    printArray(my_array, fcnptr);
    printArray(my_array, isOdd);
    
    return 0;
}
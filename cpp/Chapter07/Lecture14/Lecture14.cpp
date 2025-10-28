/*
    단언하기 assert
*/
#include <iostream>
#include <cassert>
#include <array>

using namespace std;

void printValue(const std::array<int, 5>& arr, const int& ix)
{
    assert(ix >= 0);
    assert(ix <= arr.size() - 1);
    cout << arr[ix] << endl;
}

int main()
{
    /*int number = 5;
    // works only on Debud mode
    assert(number == 5); */

    

    /*std::array<int, 5> my_array{ 1, 2, 3, 4, 5 };

    printValue(my_array, 100);*/

    /*const int x = 10;
    
    static_assert(x == 5, "x should be 5");*/

    return 0;
}
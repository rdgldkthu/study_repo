/*
    std::array 소개
*/
#include <iostream>
#include <array>
#include <algorithm>

using namespace std;

void printLength(const array<int, 5>& arr)
{
    cout << arr.size() << endl;
}

int main()
{
    std::array<int, 5> my_arr = { 1, 21, 3, 42, 5 }; // has to specify type and size

    cout << my_arr[0] << endl;
    //cout << my_arr.at(15) << endl; // exception control, slower
    cout << my_arr.size() << endl;
    printLength(my_arr);

    for (auto& element : my_arr)
        cout << element << " ";
    cout << endl;

    // sort
    std::sort(my_arr.begin(), my_arr.end());

    // sort (reverse order)
    std::sort(my_arr.rbegin(), my_arr.rend());

    for (auto& element : my_arr)
        cout << element << " ";
    cout << endl;

    return 0;
}
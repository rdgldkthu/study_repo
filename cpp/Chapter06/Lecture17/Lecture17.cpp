/*
    C++11 For-each 반복문
*/
#include <iostream>
#include <limits>
#include <algorithm>
#include <vector>

using namespace std;

int main()
{
    //int fibonacci[] = { 0, 1, 1, 2, 3, 5, 8, 13 };
    // for-each does not work with dynamically alloacted arrays, using vectors is a workaround
    vector<int> fibonacci = { 0, 1, 1, 2, 3, 5, 8, 13 };

    int max_number = std::numeric_limits<int>::lowest();

    // find max
    for (const auto& n : fibonacci)
    {
        max_number = std::max(max_number, n);
    }

    cout << max_number << endl;

    // change array values 
    for (auto& number : fibonacci)
    {
        number *= 10;
    }

    // output
    for (const auto& number : fibonacci)
    {
        cout << number << " ";
    }
    cout << endl;

    return 0;
}
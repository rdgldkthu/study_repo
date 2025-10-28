/*
    std::vector 소개
*/
#include <iostream>
#include <vector>

using namespace std;

int main()
{
    // unlike new-delete, vectors release memory automatically
    std::vector<int> arr = { 1, 2, 3, 4, 5, };
    cout << arr.size() << endl;

    // resize
    arr.resize(10);
    cout << arr.size() << endl;

    for (auto& itr : arr)
        cout << itr << " ";
    cout << endl;

    cout << arr[1] << endl;
    cout << arr.at(1) << endl;

    return 0;
}
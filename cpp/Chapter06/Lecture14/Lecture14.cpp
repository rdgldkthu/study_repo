/*
    참조 변수 Reference Variable
*/
#include <iostream>

using namespace std;

struct Something
{
    int v1;
    float v2;
};

struct Other
{
    Something st;
};

void doSomething(int& n)
{
    n = 10;
    cout << "In doSomething: " << n << endl;
}

void printElements(int(&arr)[5])
{
    for (int i = 0; i < 5; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main()
{
    int value = 5;
    int* ptr = nullptr;
    ptr = &value;

    int& ref = value;

    cout << ref << endl;

    ref = 10;

    cout << value << " " << ref << endl;

    cout << &value << endl;
    cout << &ref << endl;
    cout << ptr << endl;
    cout << &ptr << endl;

    /*int x = 5;
    int& ref = x;

    const int y = 8;
    const int& ref = y;*/

    int n = 5;
    cout << n << endl;
    doSomething(n);
    cout << n << endl;

    const int length = 5;
    int arr[length] = { 1, 2, 3, 4, 5 };
    printElements(arr);

    Other ot;
    int& v1 = ot.st.v1;
    v1 = 1;

    return 0;
}
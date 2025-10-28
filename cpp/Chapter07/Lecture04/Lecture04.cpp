/*
    주소에 의한 인수 전달 Passing Arguments by Address (Call by Address)
*/
#include <iostream>

using namespace std;

void foo(int* ptr)
{
    cout << *ptr << " " << ptr << " " << &ptr << endl;

    *ptr = 10;
}

int main()
{
    int value = 5;

    cout << value << " " << &value << endl;

    int* ptr = &value;

    cout << &ptr << endl;

    foo(ptr);
    foo(&value);
    //foo(5);

    cout << value << endl;

    return 0;
}
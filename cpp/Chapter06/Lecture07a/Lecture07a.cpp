/*
    널 포인터 Null Pointer
*/
#include <iostream>
#include <cstddef>

using namespace std;

void doSomething(double* ptr)
{
    cout << "address of pointer variable in doSomething() " << &ptr << endl;

    if (ptr != nullptr)
    {
        // do something useful
        cout << *ptr << endl;
    }
    else
    {
        // do nothing with ptr
        cout << "nullptr" << endl;
    }
}

int main()
{
    double* ptr = nullptr;

    doSomething(ptr);
    doSomething(nullptr);

    double d = 123.4;
    ptr = &d;
    doSomething(&d);
    doSomething(ptr);

    cout << "address of pointer variable in main() " << &ptr << endl;

    //std::nullptr_t nptr;

    return 0;
}
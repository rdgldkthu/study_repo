/*
    포인터 Pointer
*/
#include <iostream>
#include <typeinfo>

using namespace std;

struct Something
{
    int a, b, c, d;
};

int main()
{
    int x = 5;
    double d = 123.0;

    cout << x << endl;
    cout << &x << endl; // & : address-of operator
    cout << (int)&x << endl;

    // de-reference operator (*)
    cout << *&x << endl;

    cout << "----------" << endl;

    //typedef int* pint;
    int *ptr_x = &x;
    double* ptr_d = &d;

    cout << ptr_x << endl;
    cout << *ptr_x << endl;

    cout << ptr_d << endl;
    cout << *ptr_d << endl;

    cout << typeid(ptr_x).name() << endl;

    // memory : same size regardless of data type
    cout << sizeof(x) << endl;
    cout << sizeof(d) << endl;
    cout << sizeof(&x) << " " << sizeof(ptr_x) << endl;
    cout << sizeof(&d) << " " << sizeof(ptr_d) << endl;
    
    Something ss;
    Something* ptr_s;

    cout << sizeof(ss) << endl;
    cout << sizeof(ptr_s) << endl;

    return 0;
}
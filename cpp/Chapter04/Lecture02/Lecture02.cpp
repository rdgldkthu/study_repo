/*
    전역 변수 Global Variable
    정적 변수 Static Variable
    내부 연결 Internal Linkage
    외부 연결 External Linkage
*/
#include <iostream>
#include "MyConstants.h"

using namespace std;

// int value = 123;

static int g_a = 1; // static global : can't be accessed from other cpp files

//void doSomething()
//{
//    // int a = 1;
//    static int a = 1;    // the memory is static, memory allocated on first call
//    ++a;
//    cout << a << endl;
//}

// forward declaration
extern void doSomething();  // extern can be omitted
extern int a;

int main()
{
    /*cout << value << endl;

    int value = 1;

    cout << ::value << endl;
    cout << value << endl;*/

    /*doSomething();
    doSomething();
    doSomething();*/

    // cout << a << endl;

    cout << "In main.cpp file " << Constants::pi << " " << &Constants::pi << endl;

    doSomething();
    
    return 0;
}
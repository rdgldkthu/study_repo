/*
    클래스 템플릿 특수화
*/
#include <iostream>
#include "Storage8.h"

using namespace std;

//template<typename T>
//class A
//{
//public:
//    A(const T& input) {}
//
//    void doSomething()
//    {
//        cout << typeid(T).name() << endl;
//    }
//
//    void test() {}
//};
//
//template<>
//class A<char>
//{
//public:
//    A(const char& input) {}
//    void doSomething()
//    {
//        cout << "char type specialization" << endl;
//    }
//};

int main()
{
    /*A<int>      a_int(1);
    A<double>   a_double(3.14);
    A<char>     a_char('a');

    a_int.doSomething();
    a_double.doSomething();
    a_char.doSomething();*/

    Storage8<int> intStorage;

    for (int i = 0; i < 8; i++)
        intStorage.set(i, i);

    for (int i = 0; i < 8; i++)
        cout << intStorage.get(i) << endl;

    cout << "Size of Storage8<int> " << sizeof(Storage8<int>) << endl;

    Storage8<bool> boolStorage;
    
    for (int i = 0; i < 8; i++)
        boolStorage.set(i, i & 3);

    for (int i = 0; i < 8; i++)
        cout << std::boolalpha << boolStorage.get(i) << endl;

    cout << "Size of Storage8<bool> " << sizeof(Storage8<bool>) << endl;

    return 0;
}
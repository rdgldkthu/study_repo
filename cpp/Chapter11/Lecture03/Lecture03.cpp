/*
    유도된 Derived 클래스들의 생성 순서
*/
#include <iostream>

using namespace std;

//class Mother
//{
//public:
//    int m_i;
//
//    Mother(const int& i_in = 0)
//        : m_i(i_in)
//    {
//        cout << "Mother Constructor" << endl;
//    }
//};
//
//class Child : public Mother
//{
//public:
//    double m_d;
//public:
//    Child()
//        : Mother(0), m_d(1.0)
//    {
//        cout << "Child Constuctor" << endl;
//    }
//};

class A
{
public:
    A()
    {
        cout << "A Constructor" << endl;
    }
};

class B : public A
{
public:
    B()
    {
        cout << "B Constructor" << endl;
    }
};

class C : public B
{
public:
    C()
    {
        cout << "C Constructor" << endl;
    }
};

int main()
{
    //Child c1;
    C c;
    return 0;
}
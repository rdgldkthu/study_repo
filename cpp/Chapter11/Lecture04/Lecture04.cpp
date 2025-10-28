/*
    유도된 클래스들의 생성과 초기화
*/
#include <iostream>

using namespace std;

//class Mother
//{
//private:
//    int m_i;
//
//public:
//    Mother(const int& i_in = 0)
//        : m_i(i_in)
//    {
//        cout << "Mother Constructor" << endl;
//    }
//};
//
//class Child : public Mother
//{
//private:
//    double m_d;
//
//public:
//    Child()
//        : Mother(1024), m_d(1.0)
//    {
//        cout << "Child Constuctor" << endl;
//    }
//};

class A
{
public:
    A(int a)
    {
        cout << "A: " << a << endl;
    }

    ~A()
    {
        cout << "A Destructor" << endl;
    }
};

class B : public A
{
public:
    B(int a, double b)
        : A(a)
    {
        cout << "B: " << b << endl;
    }

    ~B()
    {
        cout << "B Destructor" << endl;
    }
};

class C : public B
{
public:
    C(int a, double b, char c)
        : B(a, b)
    {
        cout << "C: " << c << endl;
    }

    ~C()
    {
        cout << "C Destructor" << endl;
    }
};

int main()
{
    /*cout << sizeof(Mother) << endl;
    cout << sizeof(Child) << endl;*/

    C(1024, 3.14, 'a');

    return 0;
}
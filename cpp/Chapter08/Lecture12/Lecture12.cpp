/*
    친구 함수와 클래스 friend
*/
#include <iostream>

using namespace std;

class A; // forward declaration

class B
{
private:
    int m_value = 2;

    friend void doSomething(A& a, B& n);

public:
    void doSomething(A& a);
};

class A
{
private:
    int m_value = 1;

    friend void doSomething(A& a, B& n);

    //friend class B;
    friend void B::doSomething(A& a);
};

void B::doSomething(A& a)
{
    cout << a.m_value << endl;
}

void doSomething(A& a, B&b )
{
    cout << a.m_value << " " << b.m_value << endl;
}

int main()
{
    A a;
    B b;

    doSomething(a, b);

    b.doSomething(a);

    return 0;
}
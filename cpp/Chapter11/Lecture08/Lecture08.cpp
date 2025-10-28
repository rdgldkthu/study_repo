/*
    상속받은 함수를 감추기
*/
#include <iostream>

using namespace std;

class Base
{
protected:
    int m_i;

public:
    Base(int value)
        : m_i(value)
    {}

    void print()
    {
        cout << "I'm base " << endl;
    }
};

class Derived : public Base
{
private:
    double m_d;

public:
    Derived(int value)
        : Base(value)
    {}

    // can change what was inherited as protected into public
    using Base::m_i;

private:
    // can forbid using inherited functions 
    using Base::print;

    //or

    void print() = delete;
};

int main()
{
    Derived derived(7);

    derived.m_i = 1024;
    //derived.print();

    return 0;
}
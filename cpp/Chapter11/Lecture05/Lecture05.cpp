/*
    상속과 접근 지정자
*/
#include <iostream>

using namespace std;

class Base
{
public:
    int m_public;
protected:
    int m_protected;
private:
    int m_private;
};

class Derived : private Base
{
public:
    Derived()
    {
        Base::m_public = 1;
        Base::m_protected = 2;
        //Base::m_private = 3;
    }
};

class GrandChild : public Derived
{
public:
    GrandChild()
    {
        //Derived::m_public;
        //Derived::m_protected;
        //Derived::m_private;
    }
};

int main()
{
    Base base;

    base.m_public = 123;
    /*base.m_protected = 123;
    base.m_private = 123;*/

    Derived derived;
    return 0;
}
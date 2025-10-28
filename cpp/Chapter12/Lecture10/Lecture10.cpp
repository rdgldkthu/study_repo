/*
    동적 형변환 Dynamic Casting
*/
#include <iostream>
#include <string>

using namespace std;

class Base
{
public:
    int m_i = 0;

    virtual void print()
    {
        cout << "I'm Base" << endl;
    }
};

class Derived1 : public Base
{
public:
    int m_j = 1024;

    virtual void print() override
    {
        cout << "I'm Derived1" << endl;
    }
};

class Derived2 : public Base
{
public:
    string m_name = "Dr. Two";

    virtual void print() override
    {
        cout << "I'm Derived2" << endl;
    }
};

int main()
{
    Derived1 d1;
    Base* base = &d1;

    //base.m_j;

    auto* base_to_d1 = dynamic_cast<Derived1*>(base);

    cout << base_to_d1->m_j << endl;
    base_to_d1->m_j = 2048;

    cout << d1.m_j << endl;

    auto* base_to_d2 = dynamic_cast<Derived2*>(base);
    if (base_to_d2 != nullptr)
        cout << base_to_d2->m_name << endl;
    else
        cout << "dynamic cast failed" << endl;

    // however static cast will always convert (cannot check runtime error beforehand) 
    auto* sc = static_cast<Derived2*>(base);
    sc->print();

    return 0;
}
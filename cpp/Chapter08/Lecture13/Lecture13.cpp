/*
    익명 객체 anonymous
*/
#include <iostream>

using namespace std;

//class A
//{
//private:
//public:
//    int m_value;
//
//    A(const int& input)
//    {
//        m_value = input;
//        cout << m_value << " Constructor" << endl;
//    }
//
//    ~A()
//    {
//        cout << m_value << " Destructor" << endl;
//    }
//
//    void print()
//    {
//        cout << m_value << endl;
//    }
//
//    void printDouble()
//    {
//        cout << m_value * 2 << endl;
//    }
//
//};

class Cents
{
private:
    int m_cents;
public:
    Cents(const int& cents) { m_cents = cents; }
    int getCents() const { return m_cents; }
};

Cents add(const Cents& c1, const Cents& c2)
{
    return Cents(c1.getCents() + c2.getCents());
}

int main()
{
    /*A a(1);
    a.printDouble();

    A(2).printDouble();*/
    
    cout << add(Cents(6), Cents(8)).getCents() << endl;
    cout << int(6) + int(8) << endl;

    return 0;
}
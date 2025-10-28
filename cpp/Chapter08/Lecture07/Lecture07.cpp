/*
    this 포인터와 연쇄 호출 Chaining Member Functions
*/
#include <iostream>

using namespace std;

//class Simple
//{
//private:
//    int m_id;
//
//public:
//    Simple(const int& id)
//    {
//        setID(id);
//
//        cout << this << endl;
//    }
//
//    void setID(const int& id) { m_id = id; }
//    int getID() { return m_id; }
//};

class Calc
{
private:
    int m_value;

public:
    Calc(int init_value) : m_value(init_value) {}

    Calc& add(int value) { m_value += value; return *this; }
    Calc& sub(int value) { m_value -= value; return *this; }
    Calc& mult(int value) { m_value *= value; return *this; }

    void print()
    {
        cout << m_value << endl;
    }
};

int main()
{
    /*Simple s1(1), s2(2);
    s1.setID(2);
    s2.setID(4);

    cout << &s1 << " " << &s2;*/

    Calc cal(10);
    cal.add(10).sub(1).mult(2).print();

    return 0;
}
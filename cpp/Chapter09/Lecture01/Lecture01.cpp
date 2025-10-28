/*
    산술 연산자 오버로딩 Overloading 하기
*/
#include <iostream>

using namespace std;

class Cents
{
private:
    int m_cents;

public:
    Cents(int cents) { m_cents = cents; }
    int getCents() const { return m_cents; }

    Cents operator + (const Cents& c2)
    {
        return Cents(m_cents + c2.getCents());
    }
};

int main()
{
    Cents cents1(6);
    Cents cents2(8);

    cout << (cents1 + cents2 + Cents(10)).getCents() << endl;
    
    return 0;
}
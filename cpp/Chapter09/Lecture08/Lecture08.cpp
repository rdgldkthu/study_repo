/*  
    형변환 static_cast (typecast) 오버로딩 하기
*/
#include <iostream>

using namespace std;

class Cents
{
private:
    int m_cents;

public:
    Cents(int cents = 0) { m_cents = cents; }

    int getCents() const { return m_cents; }
    void setCents(int cents) { m_cents = cents; }

    operator int()
    {
        return m_cents;
    }
};

class Dollar
{
private:
    int m_dollar = 0;

public:
    Dollar(const int& input) { m_dollar = input; }

    operator Cents()
    {
        return Cents(m_dollar * 100);
    }
};

void printInt(const int& value)
{
    cout << value << endl;
}

int main()
{
    Dollar dol(2);

    Cents cents = dol;

    printInt(cents);
    return 0;
}
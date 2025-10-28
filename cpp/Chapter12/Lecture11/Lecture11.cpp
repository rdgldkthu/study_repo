/*
    유도 클래스에서 출력 연산자 사용하기
*/
#include <iostream>

using namespace std;

class Base
{
public:
    Base() {}

    friend std::ostream& operator << (std::ostream& out, const Base& b)
    {
        return b.print(out);
    }

    virtual std::ostream& print(std::ostream& out) const
    {
        out << "Base";
        return out;
    }
};

class Derived : public Base
{
public:
    Derived() {}

    virtual std::ostream& print(std::ostream& out) const override
    {
        out << "Derived";
        return out;
    }
};

int main()
{
    Base b;
    cout << b << '\n';

    Derived d;
    cout << d << '\n';

    Base& ref = d;
    cout << ref << '\n';

    return 0;
}
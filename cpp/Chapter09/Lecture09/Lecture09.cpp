/*
    복사 생성자, 복사 초기화 반환값 최적화 Return Value Optimization
*/
#include <iostream>
#include <cassert>

using namespace std;

class Fraction
{
private:
    int m_numerator;
    int m_denominator;

public:
    Fraction(int num = 0, int den = 1) 
        : m_numerator(num), m_denominator(den) 
    {
        assert(den != 0); 
    }
    Fraction(const Fraction& fraction) // copy constructor
        : m_numerator(fraction.m_numerator), m_denominator(fraction.m_denominator)
    {
        cout << "Copy constructor called" << endl;
    }

    friend std::ostream& operator << (std::ostream& out, const Fraction& f)
    {
        cout << f.m_numerator << " / " << f.m_denominator;
        return out;
    }
};

Fraction doSomething()
{
    Fraction temp(1, 2);
    cout << &temp << endl;
    return temp;
}

int main()
{
    Fraction result = doSomething(); // copy when Debug mode, optimized when Release mode
    cout << &result << endl;
    cout << result << endl;

    return 0;
}
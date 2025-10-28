/*
    생성자 Constructors
*/
#include <iostream>

using namespace std;

class Fraction
{
private:
    int m_numerator;
    int m_denominator;
public:
    Fraction(const int& num_in = 1, const int& den_in = 1)
    {
        m_numerator     = num_in;
        m_denominator   = den_in;
        cout << "Fraction constructor" << endl;
    }

    void print()
    {
        cout << m_numerator << " / " << m_denominator << endl;
    }
};

int main()
{
    Fraction frac;
    frac.print();

    //Fraction one_third(1, 3);
    Fraction one_third{ 1, 3 }; // uniform initialization does not allow type conversion
    one_third.print();

    return 0;
}
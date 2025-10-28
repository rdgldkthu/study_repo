/*
    정적 멤버 함수 Static Member Functions
*/
#include <iostream>

using namespace std;

class Something
{
public:

    class _init
    {
    public:
        _init()
        {
            s_value = 9876;
        }
    };

    Something()
        : m_value(123)//, s_value(1024) // X
    {}

    static int getValue()
    {
        // cannot use this pointer
        // return this->m_value // X
        return s_value;
    }

    int temp()
    {
        return this->s_value;
    }

private:
    static int s_value;
    int m_value;

    static _init s_initializer;
};

//int Something::s_value = 1024;
int Something::s_value;
Something::_init Something::s_initializer;


int main()
{
    cout << Something::getValue() << endl;

    Something s1, s2;
    cout << s1.getValue() << endl;

    int (Something:: * fptr1)() = &Something::temp;

    cout << (s2.*fptr1)() << endl;

    int (* fptr2)() = &Something::getValue;

    cout << fptr2() << endl;

    return 0;
}
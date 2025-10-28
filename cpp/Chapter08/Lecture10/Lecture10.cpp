/*
    정적 멤버 변수 Static Member Variables
*/
#include <iostream>

using namespace std;

int generateID()
{
    static int s_id = 0;
    return ++s_id;
}

class Something
{
public:
    static int s_value;
    static const int s_value_const = 2;
    static constexpr int s_value_constexpr = 3;
};

int Something::s_value = 1; // define in cpp

int main()
{
    cout << generateID() << endl;
    cout << generateID() << endl;
    cout << generateID() << endl;

    cout << &Something::s_value << " " << Something::s_value << endl;

    Something s1;
    Something s2;

    s1.s_value = 2;

    cout << &s1.s_value << " " << s1.s_value << endl;
    cout << &s2.s_value << " " << s2.s_value << endl;

    Something::s_value = 1024;
    cout << &Something::s_value << " " << Something::s_value;

    return 0;
}
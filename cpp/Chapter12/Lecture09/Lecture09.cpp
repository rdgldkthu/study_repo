/*
    객체 잘림 Object Slicing과 reference_wrapper
*/
#include <iostream>
#include <vector>
#include <functional>

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

class Derived : public Base
{
public:
    int m_j = 1;

    virtual void print() override
    {
        cout << "I'm Derived" << endl;
    }
};

void doSomething(Base& b)
{
    b.print();
}

int main()
{
    /*
    Derived d;
    //Base& b = d;
    Base b = d;
    b.print();
    doSomething(d);
    */

    // common mistake
    Base b;
    Derived d;
    /*
    std::vector<Base> my_vec;
    my_vec.push_back(b);
    my_vec.push_back(d);

    for (auto& ele : my_vec)
        ele.print();
    */

    // fix
    /*
    std::vector<Base*> my_vec;
    my_vec.push_back(&b);
    my_vec.push_back(&d);

    for (auto& ele : my_vec)
        ele->print();
    */

    // if you want to use reference
    std::vector<std::reference_wrapper<Base>> my_vec;
    my_vec.push_back(b);
    my_vec.push_back(d);

    for (auto& ele : my_vec)
        ele.get().print();

    return 0;
}
/*
    override, final, 공변 Covariant 반환형
*/
#include <iostream>

using namespace std;

class A
{
public:
    void print() { cout << "A" << endl; }
    virtual A* getThis() 
    { 
        cout << "A::getThis()" << endl;
        return this; 
    }
};

class B : public A
{
public:
    // explicitly declare override so compiler can help debug parameter type
    //void print(short x) override { cout << "B" << endl; }

    // forbid lower class to override function
    //void print() final { cout << "B" << endl; }

    void print() { cout << "B" << endl; }
    virtual B* getThis() 
    {
        cout << "B::getThis()" << endl;
        return this; 
    }
};

class C : public B
{
public:
    void print() { cout << "C" << endl; }
};

int main()
{
    A a;
    B b;
    C c;

    A& ref = b;
    b.getThis()->print();
    ref.getThis()->print();

    cout << typeid(b.getThis()).name() << endl;
    cout << typeid(ref.getThis()).name() << endl;

    return 0;
}
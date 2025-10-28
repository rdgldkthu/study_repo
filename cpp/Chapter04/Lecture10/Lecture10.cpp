/*
    구조체 Struct
*/
#include <iostream>
#include <string>

using namespace std;

struct Person
{
    double  height;
    float   weight;
    int     age;
    string  name;

    void print()
    {
        cout << height << " " << weight << " " << age << " " << name;
        cout << endl;
    }
};

struct Family
{
    Person me, mom, dad;
};

Person getMe()
{
    Person me{ 2.0, 100.0, 20, "Jack Jack" };
    return me;
}

struct Employee     // 2 (+ 2) + 4 + 8 = 16 // padding
{
    short   id;     // 2
    int     age;    // 4
    double  wage;   // 8
};

int main()
{
    Person me{178.8, 77.9, 24, "DK Lim"};
    me.print();

    Person me2(me);
    me2.print();

    Person me_from_func = getMe();
    me_from_func.print();

    cout << sizeof(Employee) << endl;

    return 0;
}
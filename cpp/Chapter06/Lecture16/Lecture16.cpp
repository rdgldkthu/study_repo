/*
    포인터와 참조의 멤버 선택 연산자 Member Selection Operators
*/
#include <iostream>

using namespace std;

struct Person
{
    int age;
    double weight;
};

int main()
{
    Person person;

    person.age = 25;
    person.weight = 79;

    Person& ref = person;
    ref.age = 24;
    ref.weight = 73;

    Person* ptr = &person;
    ptr->age = 24;
    (*ptr).age = 26; // possible, not common

    Person& ref2 = *ptr;
    ref2.age = 27;

    cout << &person << endl;
    cout << &ref2 << endl;

    return 0;
}
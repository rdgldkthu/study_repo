/*
    상속 Inheritance의 기본 2
*/  
#include <iostream>
#include "Student.h"
#include "Teacher.h"

using namespace std;

int main()
{
    Student student("JackJack");
    student.setName("Jack Jack");
    cout << student.getName() << endl;

    Teacher teacher1("Dr. H");
    teacher1.setName("Dr. Hong");
    cout << teacher1.getName() << endl;

    cout << student << endl;

    teacher1.doNothing();
    student.doNothing();

    teacher1.teach();
    student.study();

    return 0;
}
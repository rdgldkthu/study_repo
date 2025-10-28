/*
    집합 관계 Aggregation
*/
#include <iostream>
#include <vector>
#include <string>
#include "Lecture.h"
#include "Student.h"
#include "Teacher.h"

int main()
{
    using namespace std;

    Teacher teacher1("Prof. Hong");
    Teacher teacher2("Prof. Good");

    Student std1("Jack Jack", 0);
    Student std2("Dash", 1);
    Student std3("Violet", 2);

    // if needed outside this scope, dynamic allocation
    /*Teacher* teacher1 = new Teacher("Prof. Hong");
    Teacher* teacher2 = new Teacher("Prof. Good");

    Student* std1 = new Student("Jack Jack", 0);
    Student* std2 = new Student("Dash", 1);
    Student* std3 = new Student("Violet", 2);*/

    // Composition Relationship
    Lecture lec1("Introduction to Computer Programming");
    lec1.assignTeacher(&teacher1);
    lec1.registerStudent(&std1);
    lec1.registerStudent(&std2);
    lec1.registerStudent(&std3);

    Lecture lec2("Computational Thinking");
    lec2.assignTeacher(&teacher2);
    lec2.registerStudent(&std1);

    // test
    {
        cout << lec1 << endl;
        cout << lec2 << endl;

        // event
        lec2.study();

        cout << lec1 << endl;
        cout << lec2 << endl;
    }

    // delete memory (if needed)
    /*delete std1;
    delete std2;
    delete std3;
    
    delete teacher1;
    delete teacher2;*/
    return 0;
}
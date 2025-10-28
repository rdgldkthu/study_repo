/*
    배열 array
*/
#include <iostream>

using namespace std;

void doSomething(int student_scores[20])
{
    cout << (int)&student_scores << endl;
    cout << (int)&student_scores[0] << endl;
    cout << student_scores[0] << endl;
    cout << student_scores[1] << endl;
    cout << student_scores[2] << endl;
    cout << student_scores[3] << endl;
    cout << student_scores[4] << endl;
    cout << "Size in doSomething: " << sizeof(student_scores) << endl;
}

int main()
{
    const int num_students = 20;

    int student_scores[num_students] = { 1, 2, 3, 4, 5, };

    /*cout << (int)&(student_scores[0]) << endl;
    cout << (int)&(student_scores[1]) << endl;
    cout << (int)&(student_scores[2]) << endl;
    cout << (int)&(student_scores[3]) << endl;
    cout << (int)&(student_scores[4]) << endl;

    cout << sizeof(student_scores) << endl;*/

    doSomething(student_scores);

    cout << (int)&student_scores << endl;
    cout << (int)&student_scores[0] << endl;
    cout << student_scores[0] << endl;
    cout << student_scores[1] << endl;
    cout << student_scores[2] << endl;
    cout << student_scores[3] << endl;
    cout << student_scores[4] << endl;
    cout << "Size in main: " << sizeof(student_scores) << endl;

    return 0;
}
/*
    함수 function
    리턴값 return value
    매개변수 parameter
    인수  argument
*/
#include <iostream>

using namespace std;

int addTwoNumbers(int num1, int num2)
{
    int sum = num1 + num2;
    return sum;
}

void printHelloWorld()
{
    cout << "Hello World!" << endl;
    return;
}

int main()
{
    cout << addTwoNumbers(1, 5) << endl;
    cout << addTwoNumbers(3, 6) << endl;
    cout << addTwoNumbers(8, 12) << endl;

    printHelloWorld();

    return 0;
}
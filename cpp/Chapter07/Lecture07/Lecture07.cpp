/*
    함수 오버로딩 Function Overloading
*/
#include <iostream>

using namespace std;

int add(int x, int y)
{
    return x + y;
}

double add(double x, double y)
{
    return x + y;
}

void getRandomNumber(int& x) {}
void getRandomNumber(double& x) {}

// doing this will not trick the compiler
//typedef int my_int;
//
//void print(int x) {}
//void print(my_int x) {}

// be mindful of type ambiguity
//void print(const char* value) {}
//void print(int value) {}
//void print(unsigned int value) {}
//void print(float value) {}

int main()
{
    add(1, 2);
    add(0.14, 3.0);
    
    /*print(0);
    print('a');
    print(3.141592);*/

    return 0;
}
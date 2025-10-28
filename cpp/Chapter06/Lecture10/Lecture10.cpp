/*
    C언어 스타일의 문자열 심볼릭 상수
*/
#include <iostream>

using namespace std;

const char* getName()
{
    return "Jack Jack";
}

int main()
{
    //char name[] = "Jack Jack";
    const char* name = "Jack Jack";
    const char* name2 = getName();

    cout << name << endl;

    // same address
    cout << (uintptr_t)name << endl;
    cout << (uintptr_t)name2 << endl;

    // for character arrays, cout prints the string not the address
    /*char c = 'Q';
    cout << &c << endl;*/

    return 0;
}
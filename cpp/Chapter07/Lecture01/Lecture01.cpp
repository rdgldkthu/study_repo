/*
    매개변수 Parameter와 실인자 Argument의 구분
*/
#include <iostream>

using namespace std;

int foo(int x, int y);  // x, y : parameters

int foo(int x, int y)
{
    return x + y;
} // x and y are destroyed here

int main()
{
    int x = 1, y = 2;

    foo(6, 7);      // 6, 7 : arguments (actual parameters)
    foo(x, y + 1);
    return 0;
}
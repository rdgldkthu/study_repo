/*
    클래스 코드와 헤더 파일
*/
#include <iostream>
#include "Calc.h"

using namespace std;

int main()
{
    Calc cal(10);
    cal.add(10).sub(1).mult(2).print();

    return 0;
}
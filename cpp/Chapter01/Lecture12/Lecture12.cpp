/*
    헤더 가드 header guards
    -> 헤더 파일에 definition을 써도 문제가 생기지 않음 (#ifndef 대체)
*/
#include <iostream>
#include "my_work.h"
#include "add.h"

using namespace std;

int main()
{
    doSomething();
    return 0;
}
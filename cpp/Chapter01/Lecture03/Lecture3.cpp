/*
    객체 objects              : 의미 있는 정보가 메모리에 저장된 것 (메모리의 위치를 갖고 있음)
    변수 variables            : 메모리라는 아파트의 주소에 이름을 달아준 것
    L(eft)-values             : = 좌측
    R(ight)-values            : = 우측
    초기화 initialization
    대입 assignment
    초기화를 안했을 떄의 문제점 : 초기화되지 않은 주소에서 값을 가져오려고 할 때 런타임 에러
                                Release 모드에서는 빌드 시에 초기화되지 않은 변수에 default 값이 들어가기도 함
                                -> 문제 파악을 하지 못할 수 있음.
*/
#include <iostream>

int main(void)
{
    /*
    // x 라는 이름이 가르키고 있는 메모리 공간에 123을 대입해 저장
    int x = 123;    // initialization
    int y(4);       // initialization
    x = 5;          // assignment operator

    std::cout << x << std::endl;
    */

    // 따라해보기
    int x = 1;
    x = x + 2;
    std::cout << x << std::endl;    // x == 3

    int y = x;
    std::cout << y << std::endl;    // y == 3

    // is (x+y) l-value or r-value? -> r-value
    std::cout << x + y << std::endl;// x + y == 6

    std::cout << x << std::endl;    // x == 3

    //int z;
    //std::cout << z << std::endl;    // uninitialzed -> error

    return 0;
}
/*
    기본 자료형 fundamental data types
    character types
    integer types (signed/unsigned)
    floating-point types
    boolean type
    void type
    null pointer
*/
#include <iostream>
#include <bitset>

int main()
{
    using namespace std;
    
    bool b_value = true;
    char ch_value = 'A';
    float f_value = 3.141592f;
    double d_value = 3.141592;

    auto a_value = 3.141592;

    cout << ch_value << endl;

    cout << sizeof(d_value) << endl;

    int a(123);     // direct initialization
    int b{ 123 };   // uniform initialization <- 조금 더 엄격하다 (다른 자료형을 받지 않음, direct는 warning만 하고 변환해줌)

    int k, l, m; 

    // 변수 선언은 처음 사용 전에 하는게 디버깅 이점이 있음

    return 0;
}
/*
    C++17 함수에서 여러개의 리턴값 반환하기
*/
#include <iostream>
#include <tuple>

using namespace std;

auto my_func()
{
    return tuple(123, 456, 789, 10);
}

int main()
{
    /*auto result = my_func();
    cout << get<0>(result) << " " << get<1>(result) << endl;*/

    auto [a, b, c, d] = my_func();

    cout << a << " " << b << " " << c << " " << d << endl;
    
    return 0;
}
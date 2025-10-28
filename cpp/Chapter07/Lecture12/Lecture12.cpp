/*
    재귀적 함수 호출 Recursive Function Call
*/
#include <iostream>

using namespace std;

void countDown(int count)
{
    cout << count << endl;
    if (count > 0)
        countDown(count - 1);
}

int sumTo(int sumto)
{
    if (sumto <= 0) return 0;
    else if (sumto == 1) return 1;
    else return sumTo(sumto - 1) + sumto;
}

int fibonacci(int num)
{
    if (num <= 0)
        cout << "invalid number" << endl;
    else if (num == 1) return 0;
    else if (num == 2) return 1;
    else return fibonacci(num - 2) + fibonacci(num - 1);
}

int main()
{
    countDown(5);
    
    cout << sumTo(10) << endl;      // 55
    
    cout << fibonacci(8) << endl;   // 13
    return 0;
}
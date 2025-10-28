/*
    지역 변수의 범위 Scope 와 지속기간 Duration
*/
#include <iostream>

namespace work1::work11::work111
{   
    int a = 1;

    void doSomething()
    {
        a += 3;
    }
}
namespace work2
{
    int a = 1;

    void doSomething()
    {
        a += 5;
    }
}

int main()
{
    using namespace std;

    // apple = 3;

    int apple = 5;

    cout << apple << endl;

    {
        int apple = 1;
        cout << apple << endl;
    }

    cout << apple << endl;

    work1::work11::work111::a;
    work1::work11::work111::doSomething();

    work2::a;
    work2::doSomething();
    
    return 0;
}

// apple = 3;
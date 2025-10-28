/*
    명칭 공간 namespace
*/
#include <iostream>

using namespace std;

namespace MySpace1
{
    namespace InnerSpace
    {
        int doSomething(int a, int b)
        {
            return a + b;
        }
    }
}

namespace MySpace2
{
    int doSomething(int a, int b)
    {
        return a * b;
    }
}

int main()
{
    using namespace MySpace2;
    cout << doSomething(3,4) << endl;
    cout << MySpace1::InnerSpace::doSomething(3, 4) << endl;

    return 0;
}
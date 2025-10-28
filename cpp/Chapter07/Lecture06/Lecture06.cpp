/*
    인라인 함수 Inline Functions
*/
#include <iostream>

using namespace std;

// may or may not work, may or may not make it faster
// if applied to a function used frequently, 
// will make the file larger and end up slowing down performance
inline int min(int x, int y)
{
    return x > y ? y : x;
}

int main()
{
    cout << min(5, 6) << endl;
    // equivalent to being compiled as
    cout << (5 > 6 ? 6 : 5) << endl;

    return 0;
}
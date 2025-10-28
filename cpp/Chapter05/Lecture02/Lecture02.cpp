/*
    조건문 if
*/
#include <iostream>

int min(int x, int y)
{
    if (x > y)
        return y;
    else
        return x;
}

int main()
{
    using namespace std;

    //int x;
    //cin >> x;

    //if (x > 10)
    //{
    //    cout << x << " is greater than 10" << endl;
    //}
    //else if (x < 10)
    //{
    //    cout << x << " is less than 10" << endl;
    //}
    //else // if (x == 10)
    //{
    //    cout << x << " is exactly 10" << endl;
    //}

    /*int x, y;
    cin >> x >> y;

    if (x > 0 && y > 0)
        cout << "both are positive" << endl;
    else if (x > 0 || y > 0)
        cout << "one of them is positive" << endl;
    else
        cout << "neither is positive" << endl;*/

    int x;
    cin >> x;

    if (x > 10)
        cout << "A" << endl;
    else if (x == -1)
        return 0;
    else if (x < 0)
        cout << "B" << endl;

    return 0;
}
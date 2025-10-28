/*
    반복문 while
*/
#include <iostream>

int main()
{
    using namespace std;

    /*int count = 0;

    while (count < 10)
    {
        cout << count << endl;
        ++count;
    }

    count = 0;

    while (true)
    {
        cout << count << endl;
        ++count;
        if (count == 10)
            break;
    }*/

    //unsigned int count = 0; // overflow error

    //while (count >= 0)
    //{
    //    if (count == 0) cout << "zero";
    //    else cout << count << " ";
    //    count--;
    //}

    int outer_count = 1;
    while (outer_count <= 5)
    {
        int inner_count = 1;
        while (inner_count <= outer_count)
        {
            cout << inner_count++ << " ";
        }
        cout << endl;
        ++outer_count;
    }

    return 0;
}
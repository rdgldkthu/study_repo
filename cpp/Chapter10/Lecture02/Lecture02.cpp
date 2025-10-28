/*
    구성 관계 Composition
*/
#include <iostream>
#include "Monster.h"

using namespace std;

int main()
{
    Monster mon1("Samson", Position2D(0,0));
    cout << mon1 << endl;

    Monster mon2("Samson", Position2D(0, 0));
    cout << mon2 << endl;

    //while (true) // game loop
    {
        mon1.moveTo(1, 1);
        cout << mon1 << endl;
    }

    return 0;
}
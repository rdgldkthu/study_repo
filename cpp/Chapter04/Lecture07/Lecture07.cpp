/*
    열거형 Enumerated Types
*/
#include <iostream>
#include <typeinfo>

enum Color  // user-defined data type
{
    COLOR_BLACK,
    COLOR_RED,
    COLOR_BLUE,
    COLOR_GREEN,
    //BLUE,
};

enum Feeling
{
    HAPPY,
    JOY,
    TIRED,
    BLUE,
};

int main()
{
    using namespace std;

    Color my_color = COLOR_RED;

    cout << my_color << " " << COLOR_RED << endl;

    return 0;
}
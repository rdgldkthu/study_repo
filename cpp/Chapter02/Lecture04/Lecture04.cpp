/*
    보이드 void
*/
#include <iostream>

void my_function()
{

}

int main()
{
    // void my_void;    // can't declare

    int i = 123;
    float f = 123.456f;

    void* my_void;

    my_void = (void*)&i;
    my_void = (void*)&f;

    return 0;
}
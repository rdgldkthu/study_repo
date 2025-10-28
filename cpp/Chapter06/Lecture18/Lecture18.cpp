/*
    void 포인터
*/
#include <iostream>

using namespace std;

// void pointer, generic pointer

enum Type
{
    INT,
    FLOAT,
    CHAR,
};

int main()
{
    int     i = 5;
    float   f = 3.0;
    char    c = 'a';

    void* ptr = nullptr;

    ptr = &i;
    ptr = &c;
    ptr = &f;

    Type type = FLOAT;
    
    // doesn't work because the compiler doesn't know how many bytes to add
    //cout << ptr + 1 << endl; 

    // has address
    cout << &f << " " << ptr << endl;

    // cannot dereference, has to be casted
    //cout << *ptr << endl;
    if (type == FLOAT)
        cout << *static_cast<float*>(ptr) << endl;
    else if (type == INT)
        cout << *static_cast<int*>(ptr) << endl;

    return 0;
}
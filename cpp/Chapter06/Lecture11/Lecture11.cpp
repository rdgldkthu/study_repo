/*
    메모리 동적 할당 Dynamic Memory Allocation new와 delete
*/
#include <iostream>

using namespace std;

int main()
{
    // Stack Overflow
    // int array[1000000]; //static -> stack, dynamic -> heap
    
    //int var;
    int* ptr = new int{ 7 };
    
    cout << ptr << endl;
    cout << *ptr << endl;

    /*
    int* ptr = new (std::nothrow) int{ 7 };
    if (ptr)
    {
        cout << ptr << endl;
        cout << *ptr << endl;
    }
    else
    {
        cout << "Could not allocate memory" << endl;
    }
    */

    delete ptr;
    ptr = nullptr; // commonly used

    cout << "After delete" << endl;
    if (ptr != nullptr)
    {
        cout << ptr << endl;
        cout << *ptr << endl;
    }

    // memory leak
    while (true)
    {
        int* ptr = new int;
        cout << ptr << endl;
        //delete ptr;
    }

    return 0;
}
/*
    포인터와 정적 배열
*/
#include <iostream>

using namespace std;

struct MyStruct
{
    int array[5] = { 9, 7, 5, 3, 1 };
};

//void printArray(int array[])
void printArray(int *array)
{
    cout << sizeof(array) << endl;  //20? 
    cout << *array << endl;

    *array = 100;
}

int main()
{    
    int array[5] = { 9, 7, 5, 3, 1 };
    
    cout << array[0] << " " << array[1] << endl;
    cout << array << endl;
    cout << &(array[0]) << endl;

    cout << *array << endl;

    int* ptr = array;
    cout << ptr << endl;
    cout << *ptr << " " << *(ptr + 1) << endl;

    // mostly the same, but there are some differences
    cout << sizeof(array) << endl;  // 20
    cout << sizeof(ptr) << endl;    // 4

    printArray(array);

    // changes even outside the function
    cout << *array << endl;

    char name[] = "jackjack";
    cout << *name << endl;

    MyStruct ms;
    cout << ms.array[0] << endl;

    return 0;
}
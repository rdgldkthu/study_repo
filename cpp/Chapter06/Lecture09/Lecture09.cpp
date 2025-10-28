/*
    포인터 연산과 배열 인덱싱 Indexing
*/
#include <iostream>
    
using namespace std;

int main()
{
    double value = 7.0;
    double* ptr = &value;
    
    cout << uintptr_t(ptr - 1) << endl;
    cout << uintptr_t(ptr) << endl;
    cout << uintptr_t(ptr + 1) << endl;
    cout << uintptr_t(ptr + 2) << endl;

    int array[] = { 9, 7, 5, 3, 1 };
    int* array_ptr = array;

    for (int i = 0; i < 5; i++)
    {
        cout << *(array_ptr + i) << " " << uintptr_t(array_ptr + i) << endl;
    }

    return 0;
}
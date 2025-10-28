/*
    배열과 선택 정렬 Selection Sort
*/
#include <iostream>

using namespace std;

void printArray(const int arr[], int len)
{
    for (int i = 0; i < len; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main()
{
    const int length = 5;

    int array[length] = { 3, 5, 2, 1, 4 };

    int min_id;

    // selection sort
    for (int start_id = 0; start_id < length - 1; start_id++)
    {
        printArray(array, length);
        min_id = start_id;
        for (int current_id = start_id + 1; current_id < length; current_id++)
        {
            if (array[current_id] < array[min_id])
            {
                min_id = current_id;
            }
        }
        // swap
        int temp = array[start_id];
        array[start_id] = array[min_id];
        array[min_id] = temp;
    }

    cout << "Sorted: ";
    printArray(array, length);

    return 0;
}
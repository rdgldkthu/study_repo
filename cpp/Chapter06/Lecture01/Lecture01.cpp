/*
    배열 array
*/
#include <iostream>

using namespace std;

struct Rectangle
{
    int length;
    int width;
};

int main()
{
    cout << sizeof(Rectangle) << endl;

    Rectangle rect_arr[10];

    cout << sizeof(rect_arr) << endl;

    int my_array[]{ 1, 2, 3, 4, 5 };

    for (int i = 0; i < 5; i++)
    {
        cout << my_array[i] << endl;
    }

    // num_students should be defined during compile time 
    // -> const int or #define a big number / dynamic allocation
    /*int num_students;
    cin >> num_students;

    int student_scores[num_students];*/

    return 0;
}
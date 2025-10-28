/*
    참조에 의한 인수 전달 Passing Arguments by Reference (Call by Reference)
*/
#include <iostream>
#include <vector>

using namespace std;

//void addOne(int& y)
//{
//    y = y + 1;
//    cout << y << " " << &y << endl;
//}

//void getSinCos(const double& degrees, double& sin_out, double& cos_out)
//{
//    static const double pi = 3.141592 / 180.0;
//    const double radians = degrees * pi;
//    sin_out = std::sin(radians);
//    cos_out = std::cos(radians);
//}

//void foo(int*& ptr) // reference to pointer
//{
//    cout << ptr << " " << &ptr << endl;
//}

//void printElements(int(&arr)[4])
void printElements(const vector<int>& arr)
{

}

int main()
{
    /*int x = 5;
    cout << x << " " << &x << endl;

    addOne(x);
    cout << x << " " << &x << endl;*/

    /*double sin(0.0);
    double cos(0.0);
    getSinCos(30.0, sin, cos);

    cout << sin << " " << cos << endl;*/

    /*int x = 5;
    int* ptr = &x;

    cout << ptr << " " << &ptr << endl;
    foo(ptr);*/

    /*int arr[]{ 1, 2, 3, 4 };*/
    vector<int> arr{ 1, 2, 3, 4 };
    printElements(arr);

    return 0;
}
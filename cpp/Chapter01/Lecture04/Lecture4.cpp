/*
    입출력 스트림
*/
#include <iostream>

int main()
{
    using namespace std;
    int x = 1024;
    double pi = 3.141592;

    // std -> namespace
    cout << "I love this lecture!\n";
    cout << "x is " << x << "pi is " << pi << endl;

    cout << "abc" << "\t" << "def" << endl;
    cout << "ab" << "\t" << "def" << endl;

    cout << "\a";   // 오디오 출력

    int y = 1;
    cout << "Before your input, x was: " << y << endl;

    cin >> y;
    cout << "Your input is: " << y << endl;

    return 0;
}
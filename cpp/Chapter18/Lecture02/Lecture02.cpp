/*
    ostream으로 출력하기
*/
#include <iostream>
#include <iomanip>

using namespace std;

int main()
{
    // flags
    //{
    //    cout.setf(std::ios::showpos);
    //    cout << 108 << endl;
    //    cout.unsetf(std::ios::showpos);
    //    cout << 109 << endl;

    //    cout.setf(std::ios::uppercase);
    //    //cout.unsetf(std::ios::dec);
    //    //cout.setf(std::ios::hex);
    //    //cout.setf(std::ios::hex, std::ios::basefield);
    //    cout << std::hex;
    //    cout << 108 << endl;
    //    cout << 109 << endl;
    //    cout << std::dec;
    //    cout << 110 << endl;
    //}

    //{
    //    //cout << std::defaultfloat;
    //    //cout << std::fixed;
    //    //cout << std::scientific << std::uppercase;
    //    cout << std::showpoint;
    //    cout << std::setprecision(3) << 123.456 << endl;
    //    cout << std::setprecision(4) << 123.456 << endl;
    //    cout << std::setprecision(5) << 123.456 << endl;
    //    cout << std::setprecision(6) << 123.456 << endl;
    //    cout << std::setprecision(7) << 123.456 << endl;
    //}
    
    {
        cout << -12345 << endl;
        cout.fill('*');
        cout << std::setw(10) << -12345 << endl;
        cout << std::setw(10) << std::left << -12345 << endl;
        cout << std::setw(10) << std::right << -12345 << endl;
        cout << std::setw(10) << std::internal << -12345 << endl;
    }

    return 0;
}
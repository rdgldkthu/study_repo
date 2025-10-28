/*
    암시적 형변환 Implicit Type Conversion (coersion)
    명시적 형변환 Explicit Type Conversion (casting)
*/
#include <iostream>
#include <typeinfo>
#include <iomanip>

int main()
{
    using namespace std;

    int a = 123;
    cout << typeid(a).name() << endl;

    //// promotion
    //float f = 1.0f;
    //double d = f;

    // numeric conversion
    int i = 30000;
    char c = i;
    cout << static_cast<int>(c) << endl; // 48

    double d = 0.123456789;
    float f = d;

    cout << std::setprecision(12) << f << endl;
    
    cout << 5u - 10u << endl;

    // int, unsigned int, long, unsinged long, long long, unsigned long long, float, double, long double

    return 0;
}
/*
    부동소수점수 floating point numbers
*/
#include <iostream>
#include <iomanip>
#include <limits>
#include <cmath>

int main()
{
    using namespace std;

    //float f(123456789.0f); // 10 significant digits

    //cout << std::setprecision(16);
    //cout << f << endl;

    //double d(0.1);

    //cout << d << endl;
    //cout << std::setprecision(17);
    //cout << d << endl;

    /*cout << 3.14 << endl;
    cout << 31.4e-1 << endl;*/

    /*cout << sizeof(f) << endl;
    cout << sizeof(d) << endl;
    cout << sizeof(ld) << endl;*/

    /*cout << std::numeric_limits<float>::lowest() << endl;
    cout << std::numeric_limits<double>::lowest() << endl;
    cout << std::numeric_limits<long double>::lowest() << endl;*/

    double zero = 0.0;
    double posinf = 5.0 / zero;
    double neginf = -5.0 / zero;
    double nan = zero / zero;

    cout << posinf << " " << std::isinf(posinf) << endl; // inf
    cout << neginf << " " << std::isinf(neginf) << endl; // -inf
    cout << nan << " " << std::isnan(nan) << endl;    // nan(ind)
    cout << 0.1 << " " << std::isnan(0.1) << endl;    // nan(ind)

    return 0;
}
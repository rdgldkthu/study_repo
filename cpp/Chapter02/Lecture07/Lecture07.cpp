/*
    문자형 char
*/
#include <iostream>
#include <limits>

int main()
{
    using namespace std;

    char c1(65);
    //char c2('A');   // "Hello World"    // std::string

    //cout << c1 << " " << c2 << " " << int(c1) << " " << int(c2) << endl;

    //// c style casting
    //cout << (char)65 << endl;
    //cout << (int)'A' << endl;

    //// cpp style casting
    //cout << char(65) << endl;
    //cout << int('A') << endl;

    //// 강제적이지 않고 컴파일 가능한지 확인
    //cout << static_cast<char>(65) << endl;
    //cout << static_cast<int>('A') << endl;

    //char ch(97);
    //cout << ch << endl;
    //cout << static_cast<int>(ch) << endl;
    //cout << ch << endl;

    /*cin >> c1;
    cout << c1 << " " << static_cast<int>(c1) << endl;*/

    /*cout << sizeof(unsigned char) << endl;
    cout << (int)std::numeric_limits<unsigned char>::max() << endl;
    cout << (int)std::numeric_limits<unsigned char>::lowest() << endl;*/

    cout << "This is the first line \nsecond line";
    cout << "This is the first line" << endl;
    cout << "second line";

    // \n vs endl : 줄바꿈 vs 줄바꿈 + std::flush (버퍼 내보내기)

    wchar_t c;  // 윈도우
    char32_t c3;// 더 많은 문자

    return 0;
}
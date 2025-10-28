/*
    std::string 대입, 교환, 덧붙이기, 삽입 
*/
#include <iostream>
#include <string>

using namespace std;

int main()
{
    string str1("one");
    string str2;

    str2 = str1;
    str2 = "two";
    str2.assign("two").append(" ").append("three");
    str2 += " four";
    str2.push_back(' ');
    str2.push_back('f');
    str2.push_back('i');
    str2.push_back('v');
    str2.push_back('e');
    str2.insert(3, " Hello");

    cout << str2 << endl;

    string str3("three");

    std::swap(str1, str3);

    cout << str1 << " " << str3 << endl;

    str1.swap(str3);

    cout << str1 << " " << str3 << endl;

    return 0;
}
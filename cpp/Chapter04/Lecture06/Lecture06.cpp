/*
    문자열 std::string
*/
#include <iostream>
#include <string>
#include <limits>

int main()
{
    using namespace std;
    
    cout << "Your age? : ";
    int age;
    cin >> age;

    //std::cin.ignore(32767, '\n');
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    cout << "Your name? : ";
    string name;
    //cin >> name;
    std::getline(std::cin, name);

    cout << name << " " << age << endl;

    string a("Hello ");
    string b("World");
    string hw = a + b;  // append

    hw += " I'm good";

    cout << hw << endl;
    cout << hw.length() << endl;

    return 0;
}
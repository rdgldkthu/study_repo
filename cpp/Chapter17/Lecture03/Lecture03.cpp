/*
    std::string의 길이와 용량
*/
#include <iostream>
#include <string>

using namespace std;

int main()
{
    string my_str("012345678");

    my_str.reserve(1000);

    cout << my_str.size() << endl;
    cout << my_str.length() << endl;
    cout << my_str.capacity() << endl;
    
    cout << string().max_size() << endl;

    cout << boolalpha;
    cout << my_str.empty() << endl;

    return 0;
}
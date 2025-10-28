/*
    객체지향 프로그래밍 Object Oriented Programming과 클래스 Class
*/
#include <iostream>
#include <string>
#include <vector>

using namespace std;

// Object
// Friend : name, address, age, height, weight, ...
class Friend
{
public: // access specifier (public, private, protected)
    string  m_name;
    string  m_address;
    int     m_age;
    double  m_height;
    double  m_weight;

    void print()
    {
        cout << m_name      << " "      << m_address    << " " 
             << m_age       << " "      << m_height     << " " 
             << m_weight    << endl;
    }
};

int main()
{
    Friend jj{ "Jack Jack", "Uptown", 2, 30, 10 };  // instantiation, instance

    jj.print();

    vector<Friend> my_friends;
    my_friends.resize(2);

    for (auto& fr : my_friends)
        fr.print();

    return 0;
}
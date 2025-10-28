/*
    위임 생성자
*/
#include <iostream>
#include <string>

using namespace std;

class Student
{
private:
    int     m_id;
    string  m_name;

public:
    // it is recommended to initialize member variables in only one place
    //Student(const string& name_in) : m_id(0), m_name(name_in) {} // not recommended
    Student(const int& id_in, const string& name_in) : m_id(id_in), m_name(name_in) {}
    Student(const string& name_in) : Student(0, name_in) {} // after C++11

    // another method : make a init function and use in constructors
    /*void init(const int& id_in, const string& name_in)
    {
        m_id = id_in;
        m_name = name_in;
    }
    Student(const int& id_in, const string& name_in)
    {
        init(id_in, name_in);
    }*/


    void print()
    {
        cout << m_id << " " << m_name << endl;
    }
};

int main()
{
    Student st1(0, "Jack Jack");

    st1.print();
    return 0;
}
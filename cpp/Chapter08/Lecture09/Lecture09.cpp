/*
    클래스와 const
*/
#include <iostream>
#include <string>

using namespace std;

//class Something
//{
//public:
//    Something(const Something& st_in)
//    {
//        m_value = st_in.m_value;
//
//        cout << "Copy Constructor" << endl;
//    }
//
//    Something() 
//    {
//        cout << "Constructor" << endl;
//    }
//
//    int m_value = 0;
//
//    void setValue(int value) { m_value = value; }
//    int getValue() const
//    { 
//        return m_value; 
//    }
//};
//
////void print(const Something& st)
//void print(Something st)
//{
//    cout << &st << endl;
//    cout << st.getValue() << endl;
//}

class Something
{
public:
    string m_value = "default";

    const string& getValue() const 
    { 
        cout << "const version" << endl;
        return m_value; 
    }
    string& getValue() 
    { 
        cout << "non-const version" << endl;
        return m_value; 
    }

};

int main()
{
    //const Something something;
    ////something.setValue(3);
    //cout << something.getValue() << endl;

    //cout << &something << endl;

    //print(something);

    Something s1;
    s1.getValue() = 10;
    
    const Something s2;
    s2.getValue(); //= 1024 //not possible;

    return 0;
}
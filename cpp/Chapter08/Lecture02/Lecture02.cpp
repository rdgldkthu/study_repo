/*
    캡슐화 Encapulation, 접근 지정자 Access Specifiers, 접근 함수 Access Functions
*/
#include <iostream>

using namespace std;

class Date
{
private:
    int m_month;
    int m_day;
    int m_year;

public:
    void copyFrom(const Date& original)
    {
        m_month = original.m_month;
        m_day   = original.m_day;
        m_year  = original.m_year;
    }

    // setters
    void setDate(const int& month_input, const int& day_input, const int& year_input)
    {
        m_month = month_input;
        m_day = day_input;
        m_year = year_input;
    }
    int setMonth(const int& month_input)
    {
        m_month = month_input;
    }

    //getters
    const int& getDay()
    {
        return m_day;
    }
};

int main()
{
    Date today;
    today.setDate(8, 4, 2025);

    cout << today.getDay() << endl;

    Date copy;
    copy.copyFrom(today);

    return 0;
}
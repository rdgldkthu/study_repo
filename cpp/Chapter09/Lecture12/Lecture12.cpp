/*
    이니셜라이저 리스트 Initializer List
*/
#include <iostream>
#include <initializer_list>

using namespace std;

class IntArray
{
    //private:
public:
    unsigned m_length = 0;
    int* m_data = nullptr;

public:
    IntArray(unsigned length) : m_length(length)
    {
        m_data = new int[length];
    }

    IntArray(const std::initializer_list<int>& list)
        : IntArray(list.size())
    {
        int count = 0;
        for (auto& e : list)
        {
            m_data[count] = e;
            ++count;
        }

        // error
        /*for (unsigned count = 0; count < list.size(); ++count)
            m_data[count] = list[count];*/
    }
    ~IntArray()
    {
        delete[] m_data;
    }

    friend ostream& operator << (ostream& out, IntArray& arr)
    {
        for (unsigned i = 0; i < arr.m_length; ++i)
            out << arr.m_data[i] << " ";
        out << endl;
        return out;
    }
};

int main()
{
    int my_arr1[5] = { 1, 2, 3, 4, 5 };
    int* my_arr2 = new int[5]{ 1, 2, 3, 4, 5 };

    auto i1 = { 10, 20, 30 };

    IntArray int_array{ 1, 2, 3, 4, 5, 6, 7, 8, 9, 0 };
    cout << int_array << endl;
    return 0;
}
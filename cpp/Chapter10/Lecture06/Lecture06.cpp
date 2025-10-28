/*
    컨테이너 클래스 Container Class
*/
#include <iostream>
#include <cassert>
#include <initializer_list>

using namespace std;

class IntArray
{
private:
    int m_length = 0;
    int* m_data = nullptr;

public:
    // Constructors
    IntArray(int length)
        : m_length(length)
    {
        m_data = new int[length];
    }

    IntArray(const std::initializer_list<int>& list)
        : IntArray(list.size())
    {
        initialize(list);
    }

    IntArray(const IntArray& other)
        : m_length(other.m_length)
    {
        m_data = new int[m_length];
        for (int i = 0; i < m_length; i++)
            m_data[i] = other.m_data[i];
    }

    // Desctructor
    ~IntArray()
    {
        delete[] m_data;
    }

    // Copy assignment
    IntArray& operator=(const IntArray& other)
    {
        if (this == &other) return *this; // self-assignment check
        delete[] m_data;
        m_length = other.m_length;
        m_data = new int[m_length];
        for (int i = 0; i < m_length; i++)
            m_data[i] = other.m_data[i];
        return *this;
    }

    void initialize(const std::initializer_list<int>& list)
    {
        int count = 0;
        for (auto& e : list)
        {
            m_data[count] = e;
            ++count;
        }
    }

    void reset()
    {
        delete[] m_data;
        m_data = nullptr;
        m_length = 0;
    }

    void resize(const int& new_length)
    {
        if (new_length == m_length)
            return;

        int* temp = new int[new_length];
        int limit = (new_length < m_length) ? new_length : m_length;
        std::copy(m_data, m_data + limit, temp);
        for (int i = limit; i < new_length; i++)
            temp[i] = 0;

        delete[] m_data;
        m_data = temp;
        m_length = new_length;
    }

    void insertBefore(const int& new_int, const int& id)
    {
        assert(id < m_length);
        int* temp = new int[m_length + 1];
        int i;
        for (i = 0; i < id; i++)
            temp[i] = m_data[i];
        temp[i] = new_int;
        for (i = id + 1; i < m_length + 1; i++)
            temp[i] = m_data[i - 1];
        delete[] m_data;
        m_data = temp;
        ++m_length;
    }

    void remove(const int& id)
    {
        assert(id < m_length);
        for (int i = id; i < m_length - 1; i++)
            m_data[i] = m_data[i + 1];
        --m_length;
    }

    void push_back(const int& new_int)
    {
        int* temp = new int[m_length + 1];
        std::copy(m_data, m_data + m_length, temp);
        temp[m_length] = new_int;
        delete[] m_data;
        m_data = temp;
        ++m_length;
    }

    friend std::ostream& operator << (std::ostream& out, const IntArray& int_arr)
    {
        for (int i = 0; i < int_arr.m_length; i++)
            out << int_arr.m_data[i] << " ";
        return out;
    }
};

int main()
{
    IntArray my_arr{ 1, 3, 5, 7, 9 };
    my_arr.insertBefore(10, 1);         // 1, 10, 3, 5, 7, 9
    cout << my_arr << endl;
    my_arr.remove(3);                   // 1, 10, 3, 7, 9
    cout << my_arr << endl;
    my_arr.push_back(13);               // 1, 10, 3, 7, 9, 13
    cout << my_arr << endl;
    return 0;
}
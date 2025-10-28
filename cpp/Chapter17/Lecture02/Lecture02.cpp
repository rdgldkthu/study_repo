/*
    std::string의 여러가지 생성자들과 형변환
*/
#include <iostream>
#include <vector>
#include <string>
#include <sstream>

template <typename T>
std::string ToString(T x)
{
    std::ostringstream osstream;
    osstream << x;
    return osstream.str();
}

template <typename T>
bool FromString(const std::string& str, T& x)
{
    std::istringstream isstream(str);
    return (isstream >> x) ? true : false;
}

int main()
{
    {
        //std::string my_string("my string");
        const char* my_string = "my string";

        std::vector<char> vec;
        for (auto e : "Today is a good day.")
            vec.push_back(e);

        std::string second_string(vec.begin(), std::find(vec.begin(), vec.end(), 'g'));

        std::cout << second_string << std::endl;
    }

    {
        std::string my_str(std::to_string(1024));

        int i = std::stoi(my_str);

        my_str += std::to_string(128);

        std::cout << my_str << std::endl;
    
        std::cout << i << std::endl;
    }

    {
        std::string my_str(ToString(3.141592));

        double d;

        if (FromString(my_str, d))
            std::cout << d << std::endl;
        else
            std::cout << "conversion failed" << std::endl;

        std::cout << my_str << std::endl;
    }


    return 0;
}
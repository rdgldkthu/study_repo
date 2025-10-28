/*
    std::exception 소개
*/
#include <iostream>
#include <exception>
#include <string>

using namespace std;

class CustomException : public std::exception
{
public:
	const char* what() const noexcept override
	{
		return "Custom exception";
	}
};

int main()
{
	try
	{
		/*std::string s;
		s.resize(-1);*/

		//throw std::runtime_error("Bad thing happened");
		
		throw CustomException();
	}
	catch (std::length_error& exception)
	{
		cerr << "length error" << endl;
		cerr << exception.what() << endl;
	}
	catch (const std::exception& exception)
	{
		cout << typeid(exception).name() << endl;
		cerr << exception.what() << endl;
	}

    return 0;
}
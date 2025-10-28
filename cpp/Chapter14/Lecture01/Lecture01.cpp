/*
    예외처리의 기본 Exception Handling
*/
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main()
{
    // try, catch, throw
	try
	{
		throw string("My Error Message");
	}
	catch (int x)
	{
		cout << "Catch integer " << x << endl;
	}
	catch (double x)
	{
		cout << "Catch double " << x << endl;
	}
	catch (const char* error_message)
	{
		cout << "Catch char* " << error_message << endl;
	}
	catch (std::string error_message)
	{
		cout << "Catch string " << error_message << endl;
	}

    return 0;
}

//int findFirstChar(const char* string, char ch)
//{
//    for (size_t index = 0; index < strlen(string); ++index)
//        if (string[index] == ch)
//            return index;
//    return -1; // no match
//}
//
//double divide(int x, int y, bool& success)
//{
//    if (y == 0)
//    {
//        success = false;
//        return 0.0;
//    }
//
//    success = false;
//    return static_cast<double>(x) / y;
//}
//
//int main()
//{
//    bool success;
//    double result = divide(5, 3, success);
//
//    if (!success)
//        cerr << "An error occurred" << endl;
//    else
//        cout << "Result is " << result << endl;
//
//    ifstream input_file("temp.txt");
//    if (!input_file)
//        cerr << "Cannot open file" << endl;
//
//    return 0;
//}
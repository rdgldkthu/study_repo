/*
    문자 접근하기와 배열로의 변환
*/
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main()
{
    string my_str("abcdefg");

	try
	{
		//my_str[100] = 'X'; // no exception control for better performance
		my_str.at(100) = 'X';
	}
	catch (const std::exception& e)
	{
		cout << e.what() << endl;
	}

	//const char* arr = my_str.c_str();
	const char* arr = my_str.data(); // the same

	cout << (int)arr[6] << endl;
	cout << (int)arr[7] << endl;

	char buf[20];

	my_str.copy(buf, 5, 0);

	buf[5] = '\0';

	cout << buf << endl;

    return 0;
}
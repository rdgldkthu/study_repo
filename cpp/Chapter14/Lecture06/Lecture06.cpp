/*
    예외처리의 위험성과 단점
*/
#include <iostream>
#include <memory>

using namespace std;

// cannot throw error in a destructor
//class A
//{
//public:
//	~A()
//	{
//		throw "error";
//	}
//};

int main()
{
	try
	{
		int* i = new int[1000000];
		unique_ptr<int> up_i(i); // will handle memory 

		// do something with i
		throw "error";

		//delete[] i; // memory leak without up_i

		//A a;
	}
	catch (...)
	{
		cout << "Caught" << endl;
	}

    return 0;
}
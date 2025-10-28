/*
    함수 try
*/
#include <iostream>

using namespace std;

class A
{
private:
	int m_x;
public:
	A(int x) : m_x(x) 
	{
		if (x <= 0)
			throw 1;
	}
};

class B : public A
{
public:
	//B(int x) : A(x) {}

	B(int x) try : A(x)
	{
		// do initialization
	}
	catch (...)
	{
		cout << "Caught in B constructor " << endl;
		// rethrow happens with/without throw
		//throw;
	}
};

void doSomething()
try
{
	throw - 1;
}
catch (...)
{
	cout << "Caught in doSomething()" << endl;
}

int main()
{
	try
	{
		//doSomething();
		B b(0);
	}
	catch (...)
	{
		cout << "Caught in main()" << endl;
	}
    return 0;
}
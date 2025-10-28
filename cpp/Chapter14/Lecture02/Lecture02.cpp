/*
    예외처리와 스택 되감기 Stack Unwinding
*/
#include <iostream>

using namespace std;

//void last() throw(int) exception specifier
//void last() throw(...) exception specifier
//void last() throw() no exception specifier

void last()
{
	cout << "last" << endl;
	cout << "Throws exception" << endl;

	throw -1;
	cout << "End last()" << endl;
}

void third()
{
	cout << "third" << endl;

	last();

	cout << "End third()" << endl;
}

void second()
{
	cout << "second" << endl;

	try
	{
		third();
	}
	catch (double)
	{
		cerr << "second caught double exception" << endl;
	}

	cout << "End second()" << endl;
}

void first()
{
	cout << "first" << endl;

	try
	{
		second();
	}
	catch (int)
	{
		cerr << "first caught int exception" << endl;
	}

	cout << "End first()" << endl;
}

int main()
{
    cout << "Start" << endl;

	try
	{
		first();
	}
	catch (int)
	{
		cerr << "main caught int exception" << endl;
	}

	// uncaught exceptions
	catch (...)
	{
		cerr << "main caught ellipses exception" << endl;
	}

	cout << "End main()" << endl;

    return 0;
}
#include <iostream>
#include "MyConstants.h"

extern int a = 123;

void doSomething()
{
	using namespace std;

	cout << "In test.cpp file " << Constants::pi << " " << &Constants::pi << endl;
}
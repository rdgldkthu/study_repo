/*
    switch-case
*/
#include <iostream>

using namespace std;

enum class Colors
{
	BLACK,
	WHITE,
	RED,
	GREEN,
	BLUE,
};

void printColorName(Colors color)
{
	switch (color)
	{
	case Colors::BLACK:
		cout << "BLACK";
		break;
	case Colors::WHITE:
		cout << "WHITE";
		break;
	case Colors::RED:
		cout << "RED";
		break;
	case Colors::GREEN:
		cout << "GREEN";
		break;
	case Colors::BLUE:
		cout << "BLUE";
		break;
	default:
		cout << "not in enum class" << endl;
		break;
	}
	cout << endl;
}

int main()
{
	printColorName(Colors::BLACK);

	int x;
	cin >> x;

	switch (x)
	{
		//int a; // not recommended, declare before switch or wrap with {}
		//int b = 5; initialization should be done inside a case
	case 0:
		break;
	case 1:
		break;
	default:
		break;
	}

    return 0;
}
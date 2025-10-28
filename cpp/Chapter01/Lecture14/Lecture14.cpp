/*
	전처리기 preprocessor
	* 매그로 함수는 최근에는 잘 사용하지 않음
	* #define은 해당 파일 안에서만  
*/
#include <iostream>
#define MY_NUMBER 65
#define MAX(a, b) ((a>b) ? a : b)
#define LIKE_APPLE

using namespace std;

int main()
{
	cout << MY_NUMBER << endl;
	cout << MAX(3, 5) << endl;

#ifndef LIKE_APPLE
	cout << "Apple" << endl;
#else
	cout << "Orange" << endl;
#endif

	return 0;
}
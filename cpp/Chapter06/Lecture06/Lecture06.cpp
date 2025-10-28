/*
    C언어 스타일의 배열 문자열
*/
#include <iostream>

using namespace std;

int main()
{
    /*char myString[] = "string";

    for (int i = 0; i < 7; i++)
    {
        cout << (int)myString[i] << endl;
    }

    cout << sizeof(myString) / sizeof(char) << endl;*/

    //char myString[255];

    ////cin >> myString;
    //cin.getline(myString, 255);

    //cout << myString << endl;

    //int id = 0;
    //while (myString[id] != '\0')
    //{
    //    cout << myString[id++] << " " << (int)myString[id] << endl;
    //}
    
    char source[] = "Copy this!";
    char dest[50];
    strcpy_s(dest, 50, source);
    cout << source << endl;
    cout << dest << endl;

    strcat_s(dest, 50, source);
    cout << source << endl;
    cout << dest << endl;

    cout << strcmp(source, dest) << endl;

    return 0;
}
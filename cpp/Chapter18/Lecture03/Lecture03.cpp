/*
    문자열 스트림 String Stream
*/  
#include <iostream>
#include <string>
#include <sstream>

using namespace std;

int main()
{
    //{
    //    stringstream os;

    //    os << "Hello, World! ";  // << : insertion operator, >> : extraction operator
    //    os << "Hello, World!2" << endl;
    //    //os.str("Hello, World!3");

    //    string str = os.str();

    //    cout << str << endl;
    //}

    /*{
        stringstream os;

        os << "12345 67.89";

        string str1;
        string str2;

        os >> str1 >> str2;

        cout << str1 << "|" << str2 << endl;
    }*/

    //{
    //    stringstream os;

    //    int i = 12345;
    //    double d = 67.89;

    //    //os << i << d;
    //    os << i << " " << d;

    //    string str1, str2;

    //    os >> str1 >> str2;

    //    cout << str1 << "|" << str2 << endl;
    //}

    {
        stringstream os;

        int i = 12345;
        double d = 67.89;

        //os << i << " " << d;
        os << "12345 67.89";

        //os.str(string());
        //os.str("");
        //os.clear();

        int i2;
        double d2;

        os >> i2 >> d2;

        cout << i2 << "|" << d2 << endl;
    }

    return 0;
}
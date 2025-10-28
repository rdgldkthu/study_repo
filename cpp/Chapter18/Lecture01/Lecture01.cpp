/*
    istream으로 입력받기
*/
#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

int main()
{ 
    /*{
        char buf[5];

        cin >> setw(5) >> buf;
        cout << buf << endl;

        cin >> setw(5) >> buf;
        cout << buf << endl;

        cin >> setw(5) >> buf;
        cout << buf << endl;
    }*/

    /*{
        char buf[100];

        cin.get(buf, 5);
        cout << cin.gcount() << " " << buf << endl;

        cin.getline(buf, 100);
        cout << cin.gcount() << " " << buf << endl;
    }*/

    /*{
        string buf;

        getline(cin, buf);
        cout << cin.gcount() << " " << buf << endl;
    }*/

    {
        char buf[1024];

        cout << (char)cin.peek() << endl;

        //cin.ignore(2);

        cin >> buf;
        cout << buf << endl;

        cin.unget();

        cin.putback('A');

        cin >> buf;
        cout << buf << endl;
    }

    return 0;
}
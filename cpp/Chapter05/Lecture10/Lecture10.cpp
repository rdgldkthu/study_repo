/*  
    std::cin 더 잘쓰기
*/
#include <iostream>

using namespace std;

int getInt()
{
    while (true)
    {
        cout << "Enter an integer : ";
        int x;
        cin >> x;

        if (std::cin.fail())
        {
            std::cin.clear();
            std::cin.ignore(32767, '\n');
            cout << "Invalid number, please try again" << endl;
        }
        else
        {
            std::cin.ignore(32767, '\n');
            return x;
        }
    }
}

char getOperator()
{
    while (true)
    {
        cout << "Enter an operator (+, -) : ";
        char op;
        cin >> op;
        std::cin.ignore(32767, '\n');
        if (op == '+' || op == '-')
        {
            return op;
        }
        else
            cout << "Invalid operator, please try again" << endl;
    }
}

void printResult(int x, char op, int y)
{
    switch (op)
    {
    case '+':
        cout << x + y << endl;
        break;
    case '-':
        cout << x - y << endl;
        break;
    default:
        cout << "Invalid Operator" << endl;
        break;
    }
}

int main()
{
    int x = getInt();
    char op = getOperator();
    int y = getInt();

    printResult(x, op, y);

    return 0;
}
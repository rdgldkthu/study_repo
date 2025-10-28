/*
    std::vector를 스택처럼 사용하기
*/
#include <iostream>
#include <vector>

using namespace std;

void printStack(const std::vector<int>& stack)
{
    for (auto& e : stack)
        cout << e << " ";
    cout << endl;
}

int main()
{
    /*
    //int* v_ptr = new int[3]{ 1, 2, 3 };
    
    std::vector<int> v { 1, 2, 3 }; // size, capacity

    //v.resize(2);

    v.reserve(1024);

    for (auto& e : v)
        cout << e << " ";
    cout << endl;

    cout << v.size() << " " << v.capacity() << endl;

    // raises error
    // cout << v[2] << endl;
    // cout << v.at(2) << endl;

    // but actually keeps data in its capacity
    int* ptr = v.data();

    cout << ptr[2] << endl;
    */

    std::vector<int> stack;

    // stack.reserve(1024);

    stack.push_back(3);
    printStack(stack);

    stack.push_back(5);
    printStack(stack);

    stack.push_back(7);
    printStack(stack);

    stack.pop_back();
    printStack(stack);

    stack.pop_back();
    printStack(stack);

    stack.pop_back();
    printStack(stack);
    
    return 0;
}
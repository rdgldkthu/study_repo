/*  
    STL 반복자 Iterators 소개
*/
#include <iostream>
#include <vector>
#include <list>
#include <set>
#include <map>

using namespace std;

int main()
{
    vector<int> container;
    for (int i = 0; i < 10; i++)
        container.push_back(i);

    vector<int>::const_iterator itr;
    itr = container.begin();
    
    while (itr != container.end())
    {
        cout << *itr << " ";
        ++itr;
    }
    cout << endl;

    for (auto& e : container)
        cout << e << " ";
    cout << endl;

    for (auto itr = container.begin(); itr != container.end(); ++itr)
        cout << *itr << " ";
    cout << endl;

    return 0;
}
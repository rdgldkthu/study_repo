#include <iostream>
#include <string>
using namespace std;

int main(int argc, char **argv) {

  int n; // number of cases
  cin >> n;

  while (n--) {
    int p; // number of players
    cin >> p;

    int max_price = 0;
    string max_name;
    while (p--) {
      int c;       // price of player
      string name; // name of player
      cin >> c >> name;
      if (c > max_price) {
        max_price = c;
        max_name = name;
      }
    }

    cout << max_name << endl;
  }

  return 0;
}
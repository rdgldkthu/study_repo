#include <bits/stdc++.h>

using namespace std;

int main(int argc, char **argv) {
  string s;
  cin >> s;
  cout << (s == string(s.rbegin(), s.rend())) << endl;
  return 0;
}
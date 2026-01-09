#include <bits/stdc++.h>

using namespace std;

int M, x = 0;
string str;

int main(int argc, char **argv) {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  cin >> M;
  for (int i = 0; i <= M; i++) {
    getline(cin, str);
    auto pos = str.find(' ');
    if (pos == str.npos) {
      if (str == "all")
        x = (1 << 20) - 1;
      else if (str == "empty")
        x = 0;
    } else {
      string op = str.substr(0, pos);
      int num = stoi(str.substr(pos)) - 1;
      if (op == "add")
        x |= (1 << num);
      else if (op == "remove")
        x &= ~(1 << num);
      else if (op == "check")
        cout << ((x & (1 << num)) ? 1 : 0) << '\n';
      else if (op == "toggle")
        x ^= (1 << num);
    }
  }

  return 0;
}
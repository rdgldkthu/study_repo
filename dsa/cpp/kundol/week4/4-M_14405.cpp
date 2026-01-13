#include <bits/stdc++.h>
using namespace std;

int main(int argc, char **argv) {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  string s;
  cin >> s;

  int pos = 0;
  while (true) {
    if (pos >= s.size()) {
      cout << "YES\n";
      break;
    }
    if (s[pos] == 'p') {
      if (s.substr(pos, 2) != "pi") {
        cout << "NO\n";
        break;
      }
      pos += 2;
    } else if (s[pos] == 'k') {
      if (s.substr(pos, 2) != "ka") {
        cout << "NO\n";
        break;
      }
      pos += 2;
    } else if (s[pos] == 'c') {
      if (s.substr(pos, 3) != "chu") {
        cout << "NO\n";
        break;
      }
      pos += 3;
    } else {
      cout << "NO\n";
      break;
    }
  }

  return 0;
}

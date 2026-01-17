#include <bits/stdc++.h>
using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  string s, bomb, ans, temp;
  cin >> s >> bomb;
  int bomb_len = bomb.size();

  for (char &ch : s) {
    if (ch == bomb[0] || !temp.empty()) {
      temp += ch;
      if (temp.size() >= bomb_len) {
        bool match = true;
        for (int i = 0; i < bomb_len; i++) {
          if (temp[temp.size() - bomb_len + i] != bomb[i]) {
            match = false;
            break;
          }
        }
        if (match) {
          for (int i = 0; i < bomb_len; i++)
            temp.pop_back();
        }
      }
      continue;
    }
    ans += ch;
  }
  ans += temp;
  cout << (ans.empty() ? "FRULA" : ans) << '\n';

  return 0;
}
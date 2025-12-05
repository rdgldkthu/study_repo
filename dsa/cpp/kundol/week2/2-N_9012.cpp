#include <bits/stdc++.h>

using namespace std;

bool isValidParentheses(const string &s) {
  stack<char> st;
  for (char ch : s) {
    if (ch == '(') {
      st.push(ch);
    } else if (ch == ')') {
      if (st.empty()) {
        return false;
      }
      st.pop();
    }
  }
  return st.empty();
}

int main(int argc, char **argv) {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  int T;
  cin >> T;
  while (T--) {
    string s;
    cin >> s;
    if (isValidParentheses(s)) {
      cout << "YES\n";
    } else {
      cout << "NO\n";
    }
  }

  return 0;
}
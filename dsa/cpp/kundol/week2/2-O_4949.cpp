#include <bits/stdc++.h>

using namespace std;

bool isBalanced(const string &s) {
  stack<char> st;
  for (const char &ch : s) {
    if (ch == '(' || ch == '[') {
      st.push(ch);
    } else if (ch == ')') {
      if (st.empty() || st.top() != '(')
        return false;
      st.pop();
    } else if (ch == ']') {
      if (st.empty() || st.top() != '[')
        return false;
      st.pop();
    }
  }
  return st.empty();
}

int main(int argc, char **argv) {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  string s;
  while (true) {
    getline(cin, s);
    if (s == ".")
      break;
    if (isBalanced(s))
      cout << "yes\n";
    else
      cout << "no\n";
  }
  return 0;
}
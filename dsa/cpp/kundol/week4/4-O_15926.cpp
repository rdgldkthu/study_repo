#include <bits/stdc++.h>
using namespace std;

int main(int argc, char **argv) {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int n;
  string s;

  cin >> n;
  cin >> s;

  int ans = 0, cnt = 0;
  stack<int> st;

  bool check[200001];
  fill(check, check + 200001, false);

  for (int i = 0; i < n; i++) {
    if (s[i] == '(') st.push(i);
    if (s[i] == ')' && st.size()) {
      check[st.top()] = true;
      check[i] = true;
      st.pop();
    }
  }

  for (auto &c : check) {
    if (c) cnt++;
    else {
      ans = max(ans, cnt);
      cnt = 0;
    }
  }

  cout << ans << '\n';

  return 0;
}

#include <bits/stdc++.h>
using namespace std;

int T, N;
string dp[1001];

string better(const string &a, const string &b) {
  if (a.empty()) return b;
  if (b.empty()) return a;
  if (a.size() != b.size()) return a.size() < b.size() ? a : b;
  return a < b ? a : b;
}

string decode(const string &s) {
  string res;
  for (char c : s) {
    if (c == '1') res += '(';
    else if (c == '2') res += ')';
    else if (c == '3') res += '{';
    else if (c == '4') res += '}';
    else if (c == '5') res += '[';
    else if (c == '6') res += ']';
  }
  return res;
}

int main(int argc, char **argv) {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  dp[1] = "12"; dp[2] = "34"; dp[3] = "56";

  for (int i = 4; i <= 1000; i++) {
    for (int j = 1; j < i; j++) dp[i] = better(dp[i], dp[j] + dp[i-j]);
    if (i % 2 == 0) dp[i] = better(dp[i], "1" + dp[i/2] + "2");
    if (i % 3 == 0) dp[i] = better(dp[i], "3" + dp[i/3] + "4");
    if (i % 5 == 0) dp[i] = better(dp[i], "5" + dp[i/5] + "6");
  }

  cin >> T;
  while (T--) {
    cin >> N;
    cout << decode(dp[N]) << '\n';
  }

  return 0;
}

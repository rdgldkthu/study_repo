#include <bits/stdc++.h>
using namespace std;

bool palin[2501][2501];
int dp[2501];

int main(int argc, char **argv) {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  fill(&dp[0], &dp[0] + 2501, 3000);
  dp[0] = 0;

  string str;
  cin >> str;

  for (int diff = 0; diff < str.size(); diff++) {
    for (int start = 1; start + diff <= str.size(); start++) {
      int end = start + diff;
      if (start == end) palin[start][end] = true;
      else if (start + 1 == end) palin[start][end] = (str[start - 1] == str[end - 1]);
      else palin[start][end] = (str[start - 1] == str[end - 1]) && palin[start + 1][end - 1];
    }
  }

  for (int i = 1; i <= str.size(); i++) {
    for (int j = 1; j <= i; j++) {
      if (palin[j][i]) dp[i] = min(dp[i], dp[j - 1] + 1);
    }
  }

  cout << dp[str.size()] << '\n';

  return 0;
}

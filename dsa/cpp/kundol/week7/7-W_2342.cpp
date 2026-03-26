#include <bits/stdc++.h>
using namespace std;

int N;
int dp[5][5][100001];
vector<int> cmd;

int power(int f, int t) {
  if (f == t) return 1;
  if (f == 0) return 2;
  if (abs(f - t) == 2) return 4;
  return 3;
}

int solve(int l, int r, int id) {
  if (id == N) return 0;
  if (dp[l][r][id] != -1) return dp[l][r][id];

  dp[l][r][id] = 0;

  int left = solve(cmd[id], r, id + 1) + power(l, cmd[id]);
  int right = solve(l, cmd[id], id + 1) + power(r, cmd[id]);
  dp[l][r][id] = min(left, right);

  return dp[l][r][id];
}

int main(int argc, char **argv) {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  memset(dp, -1, sizeof(dp));

  while (true) {
    int c;
    cin >> c;
    if (c == 0) break;
    cmd.push_back(c);
  }

  N = cmd.size();

  cout << solve(0, 0, 0) << '\n';

  return 0;
}

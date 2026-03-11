#include <bits/stdc++.h>
using namespace std;

int T, W;
int plum[1001];
int dp[1001][2][31];

int solve(int t, int pos, int cnt) {
  if (cnt < 0) return -1e9;
  if (t == T) return 0;

  if (dp[t][pos][cnt] != -1) return dp[t][pos][cnt];

  dp[t][pos][cnt] =
      max(solve(t + 1, pos ^ 1, cnt - 1), solve(t + 1, pos, cnt)) +
      (pos == plum[t] - 1);

  return dp[t][pos][cnt];
}

int main(int argc, char **argv) {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  cin >> T >> W;

  for (int i = 0; i < T; i++) cin >> plum[i];

  memset(dp, -1, sizeof(dp));

  cout << max(solve(0, 0, W), solve(0, 1, W - 1)) << endl;

  return 0;
}

#include <bits/stdc++.h>
using namespace std;

int N, K;
long long dp[101][100001];

int main(int argc, char **argv) {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  memset(dp, -1, sizeof(dp));
  dp[0][0] = 0;

  cin >> N >> K;

  for (int i = 0; i < N; i++) {
    int wt, wm, bt, bm;
    cin >> wt >> wm >> bt >> bm;
    for (int j = 0; j <= K; j++) {
      if (dp[i][j] != -1) {
        if (j + wt <= K) dp[i + 1][j + wt] = max(dp[i + 1][j + wt], dp[i][j] + wm);
        if (j + bt <= K) dp[i + 1][j + bt] = max(dp[i + 1][j + bt], dp[i][j] + bm);
      }
    }
  }

  long long ans = 0;
  for (int i = 0; i <= K; i++) {
    ans = max(ans, dp[N][i]);
  }
  cout << ans << endl;

  return 0;
}

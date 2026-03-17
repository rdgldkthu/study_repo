#include <bits/stdc++.h>
using namespace std;

int N, ans = 0;
int L[20], J[20];
int dp[100];

int main(int argc, char **argv) {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  memset(dp, -1, sizeof(dp));
  dp[0] = 0;

  cin >> N;
  for (int i = 0; i < N; i++) cin >> L[i];
  for (int i = 0; i < N; i++) cin >> J[i];

  for (int i = 0; i < N; i++) {
    for (int j = 100; j >= L[i]; j--) {
      dp[j] = max(dp[j], dp[j - L[i]] + J[i]);
      if (j != 100) ans = max(ans, dp[j]);
    }
  }

  cout << ans << '\n';

  return 0;
}

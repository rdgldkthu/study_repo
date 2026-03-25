#include <bits/stdc++.h>
using namespace std;

int nums[101];
long long dp[101][21];

int main(int argc, char **argv) {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int N;
  cin >> N;

  for (int i = 0; i < N; i++) cin >> nums[i];

  dp[0][nums[0]] = 1;

  for (int i = 1; i < N - 1; i++) {
    for (int j = 0; j <= 20; j++) {
      if (dp[i - 1][j] > 0) {
        int plus = j + nums[i];
        int minus = j - nums[i];

        if (plus <= 20) dp[i][plus] += dp[i - 1][j];
        if (minus >= 0) dp[i][minus] += dp[i - 1][j];
      }
    }
  }

  cout << dp[N - 2][nums[N - 1]] << '\n';

  return 0;
}

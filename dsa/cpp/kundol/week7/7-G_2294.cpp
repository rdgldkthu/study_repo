#include <bits/stdc++.h>
using namespace std;

int n, k, coin;
int INF = 1e9;
int dp[100001];

int main(int argc, char **argv) {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  cin >> n >> k;

  fill(dp, dp + 100001, INF);
  dp[0] = 0;

  for (int i = 0; i < n; i++) {
    cin >> coin;
    for (int j = coin; j <= k; j++) {
      if (dp[j - coin] != INF) dp[j] = min(dp[j], dp[j - coin] + 1);
    }
  }

  cout << (dp[k] == INF ? -1 : dp[k]) << endl;

  return 0;
}

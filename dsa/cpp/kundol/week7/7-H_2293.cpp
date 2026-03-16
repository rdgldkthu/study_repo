#include <bits/stdc++.h>
using namespace std;

int n, k, coin;
int INF = 1e9;
int dp[100001];

int main(int argc, char **argv) {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  cin >> n >> k;

  dp[0] = 1;

  for (int i = 0; i < n; i++) {
    cin >> coin;
    for (int j = coin; j <= k; j++) {
      dp[j] = dp[j] + dp[j - coin];
    }
  }

  cout << dp[k] << endl;

  return 0;
}

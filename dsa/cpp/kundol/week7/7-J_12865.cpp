#include <bits/stdc++.h>
using namespace std;

int N, K, W, V;
long long dp[100001];

int main(int argc, char **argv) {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  cin >> N >> K;

  for (int i = 0; i < N; i++) {
    cin >> W >> V;
    for (int j = K; j >= W; j--) dp[j] = max(dp[j], dp[j - W] + V);
  }

  cout << dp[K] << '\n';

  return 0;
}

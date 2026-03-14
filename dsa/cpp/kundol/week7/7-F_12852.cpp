#include <bits/stdc++.h>
using namespace std;

int dp[1000001], parent[1000001];

int main(int argc, char **argv) {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int N; cin >> N;

  dp[1] = 0;
  for (int n = 2; n <= N; n++) {
    dp[n] = dp[n - 1] + 1;
    parent[n] = n - 1;

    if (n % 2 == 0 && dp[n] > dp[n / 2] + 1) {
      dp[n] = dp[n / 2] + 1;
      parent[n] = n / 2;
    }

    if (n % 3 == 0 && dp[n] > dp[n / 3] + 1) {
      dp[n] = dp[n / 3] + 1;
      parent[n] = n / 3;
    }
  }

  cout << dp[N] << endl;
  int curr = N;
  while (true) {
    cout << curr << " ";
    if (curr == 1) break;
    curr = parent[curr];
  }
  cout << endl;

  return 0;
}

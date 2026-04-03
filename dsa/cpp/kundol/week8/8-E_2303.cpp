#include <bits/stdc++.h>
using namespace std;

int main(int argc, char **argv) {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int N, M;
  cin >> N;
  cin >> M;

  int dp[41];
  dp[0] = 1; dp[1] = 1; dp[2] = 2;
  for (int i = 3; i <= N; i++) dp[i] = dp[i - 1] + dp[i - 2];

  int prev = 1;
  vector<int> v;
  for (int i = 0; i < M; i++) {
    int curr;
    cin >> curr;
    v.push_back(curr - prev);
    prev = curr + 1;
  }
  v.push_back(N - prev + 1);

  int ans = 1;
  for (int &e : v) {
    ans *= dp[e];
  }

  cout << ans << '\n';

  return 0;
}

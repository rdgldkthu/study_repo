#include <bits/stdc++.h>
using namespace std;

int N, M, C;
int weights[14];

int dp[11][1 << 13][21];

int solve(int bag, int mask, int capa) {
  if (bag == M || mask == (1 << N) - 1) return 0;

  int &ret = dp[bag][mask][capa];

  if (ret != -1) return ret;

  ret = solve(bag + 1, mask, C);

  for (int i = 0; i < N; i++) {
    int gem = 1 << i;
    if (!(gem & mask) && weights[i] <= capa) {
      ret = max(ret, solve(bag, mask | gem, capa - weights[i]) + 1);
    }
  }

  return ret;
}

int main(int argc, char **argv) {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  memset(dp, -1, sizeof(dp));

  cin >> N >> M >> C;

  for (int i = 0; i < N; i++) cin >> weights[i];

  cout << solve(0, 0, C) << '\n';

  return 0;
}

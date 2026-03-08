#include <bits/stdc++.h>
using namespace std;

int N, INF = 1e9;
int dist[16][16], dp[16][65536];

int solve(int curr, int visited) {
  if (visited == (1 << N) - 1) {
    if (dist[curr][0] == 0) return INF;
    return dist[curr][0];
  }

  if (dp[curr][visited] != -1) return dp[curr][visited];

  dp[curr][visited] = INF;

  for (int next = 0; next < N; next++) {
    if (visited & (1 << next)) continue;
    if (!dist[curr][next]) continue;

    int result = solve(next, visited | (1 << next));
    if (result != INF) dp[curr][visited] = min(dp[curr][visited], dist[curr][next] + result);
  }

  return dp[curr][visited];
}

int main(int argc, char **argv) {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  cin >> N;

  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      cin >> dist[i][j];
    }
  }

  memset(dp, -1, sizeof(dp));

  cout << solve(0, 1) << endl;

  return 0;
}

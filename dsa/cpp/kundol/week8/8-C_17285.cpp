#include <bits/stdc++.h>
using namespace std;

int N, M, K, T, a, b;
int cnt[301];
int dp[301][301][301];

int solve(int id, int remaining, int added) {
  if (id == N + 1) return 0;

  int &ret = dp[id][remaining][added];
  if (ret) return ret;

  if (cnt[id] >= T) {
    ret = max(ret, solve(id + 1, remaining, 0) + 1);
  } else {
    int to_add = max(0, T - cnt[id] - added);
    if (to_add <= remaining) {
      ret = max(ret, solve(id + 1, remaining - to_add, added + to_add) + 1);
    }
    ret = max(ret, solve(id + 1, remaining, added));
  }

  return ret;
}

int main(int argc, char **argv) {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  cin >> N >> M >> K >> T;

  for (int i = 0; i < M; i++) {
    cin >> a >> b;
    for (int j = a; j < b; j++) cnt[j]++;
  }

  cout << solve(1, K, 0) << '\n';

  return 0;
}

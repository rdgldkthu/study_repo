#include <bits/stdc++.h>
using namespace std;

int N, M, C;
int a[51][51];
int dp[51][51][51][51];

int solve(int y, int x, int cnt, int prev) {
  if (y > N || x > M) return 0;
  if (y == N && x == M) {
    if (cnt == 0 && a[y][x] == 0) return 1;
    if (cnt == 1 && a[y][x] > prev) return 1;
    return 0;
  }

  int& ret = dp[y][x][cnt][prev];
  if (ret != -1) return ret;

  ret = 0;

  if (a[y][x] == 0) {
    ret = (solve(y + 1, x, cnt, prev) + solve(y, x + 1, cnt, prev)) % 1000007;
  } else if (a[y][x] > prev) {
    ret = (solve(y + 1, x, cnt - 1, a[y][x]) + solve(y, x + 1, cnt - 1, a[y][x])) % 1000007;
  }

  return ret;
}

int main(int argc, char **argv) {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  memset(dp, -1, sizeof(dp));

  cin >> N >> M >> C;

  for (int i = 1; i <= C; i++) {
    int y, x;
    cin >> y >> x;
    a[y][x] = i;
  }

  for (int i = 0; i <= C; i++) cout << solve(1, 1, i, 0) << " ";
  cout << endl;

  return 0;
}

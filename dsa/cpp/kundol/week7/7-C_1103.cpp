#include <bits/stdc++.h>
using namespace std;

int N, M;
int a[50][50];
int dp[50][50];
bool visited[50][50];
const int dy[] = {-1, 0, 1, 0};
const int dx[] = {0, -1, 0, 1};

int solve(int y, int x) {
  if (y < 0 || y >= N || x < 0 || x >= M) return 0;
  if (a[y][x] == -1) return 0;

  if (visited[y][x]) {
    cout << -1 << endl;
    exit(0);
  }

  if (dp[y][x] != -1) return dp[y][x];

  visited[y][x] = true;
  dp[y][x] = 0;

  for (int i = 0; i < 4; i++) {
    int ny = y + dy[i] * a[y][x];
    int nx = x + dx[i] * a[y][x];
    dp[y][x] = max(dp[y][x], solve(ny, nx));
  }

  visited[y][x] = false;
  dp[y][x] += 1;

  return dp[y][x];
}

int main(int argc, char **argv) {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  cin >> N >> M;

  for (int i = 0; i < N; i++) {
    string s;
    cin >> s;
    for (int j = 0; j < M; j++) {
      if (s[j] == 'H') a[i][j] = -1;
      else a[i][j] = s[j] - '0';
    }
  }

  memset(dp, -1, sizeof(dp));

  cout << solve(0, 0) << endl;

  return 0;
}

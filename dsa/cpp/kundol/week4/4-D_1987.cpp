#include <bits/stdc++.h>

using namespace std;

int R, C, ans;
int board[20][20];
const int dy[4] = {-1, 0, 1, 0};
const int dx[4] = {0, 1, 0, -1};

void solve(int y, int x, int mask, int cnt) {
  ans = max(ans, cnt);
  for (int i = 0; i < 4; i++) {
    int ny = y + dy[i];
    int nx = x + dx[i];
    if (ny < 0 || ny >= R || nx < 0 || nx >= C) continue;
    int next_mask = 1 << (board[ny][nx] - 'A');
    if (mask & next_mask) continue;
    solve(ny, nx, mask | next_mask, cnt + 1);
  }
}

int main(int argc, char **argv) {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  cin >> R >> C;
  for (int i = 0; i < R; i++) {
    string s;
    cin >> s;
    for (int j = 0; j < C; j++)
      board[i][j] = s[j];
  }

  solve(0, 0, 1 << (board[0][0] - 'A'), 1);

  cout << ans << '\n';

  return 0;
}
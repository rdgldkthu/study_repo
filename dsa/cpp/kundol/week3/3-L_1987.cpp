#include <bits/stdc++.h>

using namespace std;

char board[20][20];
bool visited[26];
const int dy[4] = {-1, 0, 1, 0};
const int dx[4] = {0, 1, 0, -1};
int R, C, ans = 0;

void DFS(int y, int x, int cnt) {
  ans = max(ans, cnt);
  for (int i = 0; i < 4; ++i) {
    int ny = y + dy[i];
    int nx = x + dx[i];
    if (ny < 0 || ny >= R || nx < 0 || nx >= C) continue;
    int next = static_cast<int>(board[ny][nx] - 'A');
    if (visited[next]) continue;
    visited[next] = true;
    DFS(ny, nx, cnt + 1);
    visited[next] = false;
  }
}

int main(int argc, char **argv) {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  cin >> R >> C;
  for (int i = 0; i < R; ++i) {
    string s;
    cin >> s;
    for (int j = 0; j < C; ++j)
      board[i][j] = s[j];
  }

  visited[board[0][0] - 'A'] = true;
  DFS(0, 0, 1);
  cout << ans << '\n';

  return 0;
}

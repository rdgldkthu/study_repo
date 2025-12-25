#include <bits/stdc++.h>

using namespace std;

int R, C, K, cnt = 0;
char grid[5][5];
bool visited[5][5];
const int dy[4] = {-1, 0, 1, 0};
const int dx[4] = {0, 1, 0 ,-1};

void DFS(int y, int x, int dist) {
  if (dist > K) return;
  if (y == 0 && x == C - 1 && dist == K) {
    cnt++;
    return;
  }
  for (int i = 0; i < 4; i++) {
    int ny = y + dy[i];
    int nx = x + dx[i];
    if (ny < 0 || ny >= R || nx < 0 || nx >= C) continue;
    if (visited[ny][nx]) continue;
    if (grid[ny][nx] == 'T') continue;
    visited[ny][nx] = true;
    DFS(ny, nx, dist + 1);
    visited[ny][nx] = false;
  }
}

int main(int argc, char **argv) {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  cin >> R >> C >> K;

  for (int i = 0; i < R; i++) {
    string s;
    cin >> s;
    for (int j = 0; j < C; j++) {
        grid[i][j] = s[j];
    }
  }

  visited[R-1][0] = true;
  DFS(R-1, 0, 1);

  cout << cnt << '\n';

  return 0;
}
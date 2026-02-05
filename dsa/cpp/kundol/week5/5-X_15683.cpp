#include <bits/stdc++.h>
using namespace std;

int N, M, ans = 64;
int grid[8][8];
const int dy[4] = {-1, 0, 1, 0};
const int dx[4] = {0, 1, 0, -1};
vector<pair<int, int>> cctvs;

vector<pair<int, int>> fill1side(int y, int x, int dir) {
  vector<pair<int, int>> changes;
  int ny = y, nx = x;
  while (true) {
    ny += dy[dir];
    nx += dx[dir];
    if (ny < 0 || ny >= N || nx < 0 || nx >= M) break;
    if (grid[ny][nx] == 6) break;
    if (grid[ny][nx] == 0) {
      grid[ny][nx] = -1;
      changes.push_back({ny, nx});
    }
  }
  return changes;
}

void dfs(int id) {
  if (id == cctvs.size()) {
    int cnt = 0;
    for (int y = 0; y < N; y++) {
      for (int x = 0; x < M; x++) {
        if (grid[y][x] == 0) cnt++;
      }
    }
    ans = min(ans, cnt);
    return;
  }

  auto [y, x] = cctvs[id];
  int type = grid[y][x];

  for (int dir = 0; dir < 4; dir++) {
    vector<pair<int, int>> changes;

    if (type == 5) {
      if (dir > 0) break;
      for (int i = 0; i < 4; i++) {
        int d = (dir + i) % 4;
        auto c = fill1side(y, x, d);
        changes.insert(changes.end(), c.begin(), c.end());
      }
    } else if (type == 4) {
      for (int i = 0; i < 3; i++) {
        int d = (dir + i) % 4;
        auto c = fill1side(y, x, d);
        changes.insert(changes.end(), c.begin(), c.end());
      }
    } else if (type == 3) {
      for (int i = 0; i < 2; i++) {
        int d = (dir + i) % 4;
        auto c = fill1side(y, x, d);
        changes.insert(changes.end(), c.begin(), c.end());
      }
    } else if (type == 2) {
      for (int i = 0; i < 3; i += 2) {
        int d = (dir + i) % 4;
        auto c = fill1side(y, x, d);
        changes.insert(changes.end(), c.begin(), c.end());
      }
    } else {
      auto c = fill1side(y, x, dir);
      changes.insert(changes.end(), c.begin(), c.end());
    }
    dfs(id + 1);
    for (auto &[y, x] : changes) grid[y][x] = 0;
  }
}

int main(int argc, char **argv) {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  cin >> N >> M;
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < M; j++) {
      cin >> grid[i][j];
      if (1 <= grid[i][j] && grid[i][j] <= 5)
        cctvs.push_back({i, j});
    }
  }

  dfs(0);

  cout << ans << '\n';

  return 0;
}

#include <bits/stdc++.h>

using namespace std;

int R, C;
char a[1000][1000];
int visited[1000][1000];
int fire_lut[1000][1000];
vector<pair<int, int>> fire;
queue<pair<int, int>> q;
const int dy[] = {-1, 0, 1, 0};
const int dx[] = {0, 1, 0, -1};

void spreadFireBFS(int y0, int x0) {
  memset(visited, 0, sizeof(visited));
  q.push({y0, x0});
  visited[y0][x0] = 1;
  while (!q.empty()) {
    auto [y, x] = q.front();
    q.pop();
    for (int i = 0; i < 4; ++i) {
      int ny = y + dy[i];
      int nx = x + dx[i];
      if (ny < 0 || ny >= R || nx < 0 || nx >= C)
        continue;
      if (a[ny][nx] != '#' && !visited[ny][nx]) {
        visited[ny][nx] = 1;
        int new_time = fire_lut[y][x] + 1;
        if (fire_lut[ny][nx] == 0)
          fire_lut[ny][nx] = new_time;
        else
          fire_lut[ny][nx] = min(fire_lut[ny][nx], new_time);
        q.push({ny, nx});
      }
    }
  }
}

int escapeBFS(int y0, int x0) {
  memset(visited, 0, sizeof(visited));
  visited[y0][x0] = 1;
  q.push({y0, x0});
  while (!q.empty()) {
    auto [y, x] = q.front();
    q.pop();

    // Exit condition
    if (y == 0 || y == R - 1 || x == 0 || x == C - 1) {
      return visited[y][x];
    }

    for (int i = 0; i < 4; ++i) {
      int ny = y + dy[i];
      int nx = x + dx[i];
      if (ny < 0 || ny >= R || nx < 0 || nx >= C)
        continue;
      if (a[ny][nx] != '#' && !visited[ny][nx]) {
        visited[ny][nx] = visited[y][x] + 1;
        // Push to queue only if Joe can reach this square before fire does
        if (visited[ny][nx] < fire_lut[ny][nx])
          q.push({ny, nx});
      }
    }
  }
  return 0;
}

int main(int argc, char **argv) {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> R >> C;

  pair<int, int> init_J;
  for (int i = 0; i < R; ++i) {
    string row;
    cin >> row;
    for (int j = 0; j < C; ++j) {
      char col = row[j];
      a[i][j] = col;
      if (col == 'J') {
        init_J = {i, j};
      }
      if (col == 'F') {
        fire.push_back({i, j});
        fire_lut[i][j] = 1;
      }
    }
  }

  // BFS to spread fire and record time of arrival on each square
  for (auto &[y, x] : fire) {
    spreadFireBFS(y, x);
  }
  // If there is no fire at all, fill fire_lut with a big enough value
  if (fire.empty()) {
    memset(fire_lut, R * C, sizeof(fire_lut));
  }

  // BFS to find a possible escape path
  int time = escapeBFS(init_J.first, init_J.second);

  cout << (time ? to_string(time) : "IMPOSSIBLE") << endl;

  return 0;
}
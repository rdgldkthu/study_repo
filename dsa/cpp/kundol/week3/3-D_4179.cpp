#include <bits/stdc++.h>

using namespace std;

int R, C;
char a[1000][1000];
int joe_time[1000][1000];
int fire_time[1000][1000];
queue<pair<int, int>> q;
const int dy[] = {-1, 0, 1, 0};
const int dx[] = {0, 1, 0, -1};

int main(int argc, char **argv) {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> R >> C;

  int y0, x0;
  for (int i = 0; i < R; ++i) {
    string row;
    cin >> row;
    for (int j = 0; j < C; ++j) {
      char col = row[j];
      a[i][j] = col;
      if (col == 'J') {
        y0 = i;
        x0 = j;
      }
      if (col == 'F') {
        q.push({i, j});
        fire_time[i][j] = 1;
      }
    }
  }

  // If no fire, set fire_lut to a big enough value
  if (q.empty()) {
    memset(fire_time, R * C, sizeof(fire_time));
  }

  // BFS to spread fire and record time of arrival on each square
  while (!q.empty()) {
    auto [y, x] = q.front();
    q.pop();
    for (int i = 0; i < 4; ++i) {
      int ny = y + dy[i];
      int nx = x + dx[i];
      if (ny < 0 || ny >= R || nx < 0 || nx >= C)
        continue;
      if (a[ny][nx] != '#' && !fire_time[ny][nx]) {
        fire_time[ny][nx] = fire_time[y][x] + 1;
        q.push({ny, nx});
      }
    }
  }

  // BFS to find a possible escape path
  joe_time[y0][x0] = 1;
  q.push({y0, x0});
  while (!q.empty()) {
    auto [y, x] = q.front();
    q.pop();

    // Exit condition
    if (y == 0 || y == R - 1 || x == 0 || x == C - 1) {
      cout << joe_time[y][x] << endl;
      return 0;
    }

    for (int i = 0; i < 4; ++i) {
      int ny = y + dy[i];
      int nx = x + dx[i];
      if (ny < 0 || ny >= R || nx < 0 || nx >= C)
        continue;
      if (a[ny][nx] != '#' && !joe_time[ny][nx]) {
        joe_time[ny][nx] = joe_time[y][x] + 1;
        // Push to queue only if Joe can reach this square before fire does
        if (joe_time[ny][nx] < fire_time[ny][nx])
          q.push({ny, nx});
      }
    }
  }

  cout << "IMPOSSIBLE" << endl;
  return 0;
}
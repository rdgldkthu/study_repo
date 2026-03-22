#include <bits/stdc++.h>
using namespace std;

struct Horse { int y, x, dir; } horses[12];
int color[14][14];
vector<int> board[14][14];
const int dy[4] = {0, 0, -1, 1};
const int dx[4] = {1, -1, 0, 0};

int main(int argc, char **argv) {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int N, K;
  cin >> N >> K;

  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      cin >> color[i][j];
    }
  }

  for (int i = 0; i < K; i++) {
    int y, x, dir;
    cin >> y >> x >> dir;
    y--; x--; dir--;
    horses[i] = {y, x, dir};
    board[y][x].push_back(i);
  }

  for (int turn = 1; turn <= 1000; turn++) {
    for (int cur = 0; cur < K; cur++) {
      int y = horses[cur].y;
      int x = horses[cur].x;
      int dir = horses[cur].dir;

      int ny = y + dy[dir];
      int nx = x + dx[dir];

      if (ny < 0 || ny >= N || nx < 0 || nx >= N || color[ny][nx] == 2) {
        dir ^= 1;
        horses[cur].dir = dir;

        ny = y + dy[dir];
        nx = x + dx[dir];

        if (ny < 0 || ny >= N || nx < 0 || nx >= N || color[ny][nx] == 2) continue;
      }

      vector<int> &v = board[y][x];
      vector<int> &nv = board[ny][nx];

      auto pos = find(v.begin(), v.end(), cur);

      if (color[ny][nx] == 1) reverse(pos, v.end());

      for (auto id = pos; id != v.end(); id++) {
        nv.push_back(*id);
        horses[*id].y = ny;
        horses[*id].x = nx;
      }

      v.erase(pos, v.end());

      if (board[ny][nx].size() >= 4) {
        cout << turn << '\n';
        return 0;
      }
    }
  }

  cout << -1 << '\n';

  return 0;
}

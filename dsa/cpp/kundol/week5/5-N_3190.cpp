#include <bits/stdc++.h>
using namespace std;

enum Direction { UP, RIGHT, DOWN, LEFT };
char C;
int N, K, L, X, ny, nx, cy = 0, cx = 0, dir = RIGHT, time_s = 0, grid[100][100];
const int dy[4] = {-1, 0, 1 ,0};
const int dx[4] = {0, 1, 0, -1};
queue<pair<int, int>> q;
queue<pair<int, char>> orders;

int main(int argc, char **argv) {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  cin >> N;
  cin >> K;
  for (int i = 0; i < K; i++) {
    int y, x;
    cin >> y >> x;
    grid[y - 1][x - 1] = 1;
  }
  cin >> L;
  for (int i = 0; i < L; i++) {
    cin >> X >> C;
    orders.push({X, C});
  }

  q.push({0,0});
  grid[0][0] = -1;
  while (true) {
    time_s++;
    ny = cy + dy[dir];
    nx = cx + dx[dir];
    if (ny < 0 || ny >= N || nx < 0 || nx >= N || grid[ny][nx] == -1) {
      cout << time_s << '\n';
      return 0;
    }
    if (grid[ny][nx] != 1) {
      grid[q.front().first][q.front().second] = 0;
      q.pop();
    }
    q.push({ny, nx});
    grid[ny][nx] = -1;
    cy = ny; cx = nx;

    if (!orders.empty() && orders.front().first == time_s) {
      if (orders.front().second == 'D') dir = (dir + 1) % 4;
      if (orders.front().second == 'L') dir = (dir + 3) % 4;
      orders.pop();
    }
  }

  return 0;
}

#include <bits/stdc++.h>

using namespace std;

int N, M, cnt = 0, max1 = 0, max2 = 0;
int castle[50][50], visited[50][50];
const int dy[4] = {0, -1, 0, 1};
const int dx[4] = {-1, 0, 1, 0};
map<int, int> rooms;

int dfs(int y, int x, int marker) {
  int cnt = 1;
  for (int i = 0; i < 4; i++) {
    if (castle[y][x] & (1 << i))
      continue;
    int ny = y + dy[i];
    int nx = x + dx[i];
    if (ny < 0 || ny >= M || nx < 0 || nx >= N)
      continue;
    if (visited[ny][nx])
      continue;
    visited[ny][nx] = marker;
    cnt += dfs(ny, nx, marker);
  }
  return cnt;
}

int main(int argc, char **argv) {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  cin >> N >> M;
  for (int i = 0; i < M; i++) {
    for (int j = 0; j < N; j++) {
      cin >> castle[i][j];
    }
  }

  for (int i = 0; i < M; i++) {
    for (int j = 0; j < N; j++) {
      if (!visited[i][j]) {
        cnt++;
        visited[i][j] = cnt;
        int room_size = dfs(i, j, cnt);
        rooms.insert({cnt, room_size});
        max1 = max(max1, room_size);
      }
    }
  }

  for (int y = 0; y < M; y++) {
    for (int x = 0; x < N; x++) {
      int here = visited[y][x];
      int east = visited[y][x + 1];
      int south = visited[y + 1][x];
      if (x < N - 1 && here != east)
        max2 = max(max2, rooms[here] + rooms[east]);
      if (y < M - 1 && here != south)
        max2 = max(max2, rooms[here] + rooms[south]);
    }
  }

  cout << cnt << '\n' << max1 << '\n' << max2 << '\n';

  return 0;
}
#include <bits/stdc++.h>

using namespace std;

int N, M;
int y, x;
int maze[100][100], visited[100][100];
const int dy[] = {-1, 0, 1, 0};
const int dx[] = {0, 1, 0, -1};

int main(int argc, char **argv) {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> N >> M;

  for (int i = 0; i < N; ++i) {
    string temp;
    cin >> temp;
    for (int j = 0; j < M; ++j) {
        maze[i][j] = temp[j] - '0';
    }
  }

  queue<pair<int, int>> q;
  visited[0][0] = 1;
  q.push({0, 0});

  while(q.size()) {
    tie(y, x) = q.front(); q.pop();
    for (int i = 0; i < 4; ++i) {
      int ny = y + dy[i];
      int nx = x + dx[i];
      if (ny < 0 || ny >= N || nx < 0 || nx >= M) continue;
      if (maze[ny][nx] == 0) continue;
      if (visited[ny][nx]) continue;
      visited[ny][nx] = visited[y][x] + 1;
      q.push({ny, nx});
    }
  }

  cout << visited[N-1][M-1] << '\n';

  return 0;
}
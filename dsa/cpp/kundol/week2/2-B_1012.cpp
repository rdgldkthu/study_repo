#include <bits/stdc++.h>

using namespace std;

int M, N, K;
int a[50][50], visited[50][50];
const int dy[] = {-1, 0, 1, 0};
const int dx[] = {0, 1, 0, -1};

void DFS(int y, int x) {
  visited[y][x] = 1;
  for (int i = 0; i < 4; ++i) {
    int ny = y + dy[i];
    int nx = x + dx[i];
    if (ny < 0 || ny >= N || nx < 0 || nx >= M) continue;
    if (a[ny][nx] == 0) continue;
    if (visited[ny][nx]) continue;
    DFS(ny, nx);
  }
}

int main(int argc, char **argv) {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  int T;
  cin >> T;

  while (T--) {
    cin >> M >> N >> K;

    memset(a, 0, sizeof(a));
    memset(visited, 0, sizeof(visited));

    for (int i = 0; i < K; ++i) {
        int X, Y;
        cin >> X >> Y;
        a[Y][X] = 1;
    }

    int cnt = 0;
    for (int i = 0; i < N; ++i) {
      for (int j = 0; j < M; ++j) {
        if (a[i][j] && !visited[i][j]) {
          DFS(i, j);
          cnt++;
        }
      }
    }

    cout << cnt << '\n';
  }

  return 0;
}
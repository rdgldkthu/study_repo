#include <bits/stdc++.h>

using namespace std;

int N;
int a[100][100], visited[100][100];
const int dy[] = {-1, 0, 1, 0};
const int dx[] = {0, 1, 0, -1};

void DFS(int y, int x, int h) {
  visited[y][x] = 1;
  for (int i = 0; i < 4; ++i) {
    int ny = y + dy[i];
    int nx = x + dx[i];
    if (ny < 0 || ny >= N || nx < 0 || nx >= N) continue;
    if (a[ny][nx] > h && !visited[ny][nx]) DFS(ny, nx, h);
  }
}

int main(int argc, char **argv) {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> N;

  int temp_h, min_h = 101, max_h = 0;
  for (int i = 0; i < N; ++i) {
    for (int j = 0; j < N; ++j) {
      cin >> temp_h;
      a[i][j] = temp_h;
      min_h = temp_h < min_h ? temp_h : min_h;
      max_h = temp_h > max_h ? temp_h : max_h;
    }
  }

  int max_safe = 1;
  for (int h = min_h; h < max_h; ++h) {
    int cnt = 0;
    memset(visited, 0, sizeof(visited));

    for (int y = 0; y < N; ++y) {
      for (int x = 0; x < N; ++x) {
        if (a[y][x] > h && !visited[y][x]) {
          DFS(y, x, h); cnt++;
        }
      }
    }

    cout << "for h: " << h << " cnt: " << cnt << endl;

    max_safe = cnt > max_safe ? cnt : max_safe;
  }

  cout << max_safe << '\n';

  return 0;
}
#include <bits/stdc++.h>

using namespace std;

int M, N, K;
int a[100][100], visited[100][100];
const int dy[] = {-1, 0, 1, 0};
const int dx[] = {0, 1, 0, -1};

int DFS(int y, int x) {
  int area = 1;
  visited[y][x] = 1;
  for (int i = 0; i < 4; ++i) {
    int ny = y + dy[i];
    int nx = x + dx[i];
    if (ny < 0 || ny >= M || nx < 0 || nx >= N)
      continue;
    if (!a[ny][nx] && !visited[ny][nx])
      area += DFS(ny, nx);
  }
  return area;
}

int main(int argc, char **argv) {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> M >> N >> K;

  while (K--) {
    int ldx, ldy, rux, ruy;
    cin >> ldx >> ldy >> rux >> ruy;
    for (int y = ldy; y < ruy; ++y)
      for (int x = ldx; x < rux; ++x)
        a[y][x] = 1;
  }

  int cnt = 0;
  vector<int> areas;
  for (int y = 0; y < M; ++y) {
    for (int x = 0; x < N; ++x) {
      if (!a[y][x] && !visited[y][x]) {
        areas.push_back(DFS(y, x));
        cnt++;
      }
    }
  }

  cout << cnt << '\n';
  sort(areas.begin(), areas.end());
  for (auto &a : areas)
    cout << a << ' ';
  cout << '\n';

  return 0;
}

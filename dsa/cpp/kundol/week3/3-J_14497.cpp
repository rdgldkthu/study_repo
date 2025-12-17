#include <bits/stdc++.h>

using namespace std;

char classroom[300][300];
int visited[300][300];
const int dy[4] = {-1, 0, 1, 0};
const int dx[4] = {0, 1, 0, -1};

int main(int argc, char **argv) {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int N, M;
  cin >> N >> M;
  int x1, y1, x2, y2;
  cin >> y1 >> x1 >> y2 >> x2;
  y1--; x1--; y2--; x2--;

  for (int i = 0; i < N; ++i) {
    string row;
    cin >> row;
    for (int j = 0; j < M; ++j)
        classroom[i][j] = row[j];
  }

  int cnt = 0;
  while (classroom[y2][x2] == '#') {
    fill(&visited[0][0], &visited[0][0] + 300 * 300, 0);
    queue<pair<int, int>> q;
    q.push({y1, x1});
    while (!q.empty()) {
      int y = q.front().first;
      int x = q.front().second;
      q.pop();
      if (classroom[y][x] == '#' || classroom[y][x] == '1') {
        classroom[y][x] = '0';
      } else {
        for (int i = 0; i < 4; ++i) {
          int ny = y + dy[i];
          int nx = x + dx[i];
          if (ny < 0 || ny >= N || nx < 0 || nx >= M || visited[ny][nx])
            continue;
          visited[ny][nx] = 1;
          q.push({ny, nx});
        }
      }
    }
    cnt++;
  }

  cout << cnt << '\n';

  return 0;
}

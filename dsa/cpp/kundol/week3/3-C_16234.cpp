#include <bits/stdc++.h>

using namespace std;

int N, L, R, sum;
int a[50][50], visited[50][50];
vector<pair<int, int>> v;

const int dy[4] = {-1, 0, 1, 0};
const int dx[4] = {0, 1, 0 ,-1};

void DFS(int y, int x, vector<pair<int, int>> &v) {
  visited[y][x] = 1;
  sum += a[y][x];
  v.push_back({y, x});
  for (int i = 0; i < 4; ++i) {
    int ny = y + dy[i];
    int nx = x + dx[i];
    if (ny < 0 || ny >= N || nx < 0 || nx >= N) continue;
    if (visited[ny][nx]) continue;
    int diff = abs(a[ny][nx] - a[y][x]);
    if (L <= diff && diff <= R) DFS(ny, nx, v);
  }
}

int main(int argc, char **argv) {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> N >> L >> R;

  for (int i = 0; i < N; ++i) {
    for (int j = 0; j < N; ++j) {
      cin >> a[i][j];
    }
  }

  int days = 0;

  while (true) {
    memset(visited, 0, sizeof(visited));
    bool end_flag = true;
    for (int i = 0; i < N; ++i) {
      for (int j = 0; j < N; ++j) {
        if (!visited[i][j]) {
          sum = 0;
          v.clear();
          DFS(i, j, v);
          if (v.size() == 1) continue;
          int new_pop = sum / v.size();
          for (auto &[y, x] : v) {
            a[y][x] = new_pop;
            end_flag = false;
          }
        }
      }
    }
    if (end_flag) break;
    days++;
  }

  cout << days << '\n';

  return 0;
}
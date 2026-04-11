#include <bits/stdc++.h>
using namespace std;
using tiii = tuple<int, int, int>;

int N, M, H;
int tank[1001][1001];
int hor[1001][1001];
int ver[1001][1001];

int main(int argc, char **argv) {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  priority_queue<tiii, vector<tiii>, greater<tiii>> pq;

  cin >> N >> M >> H;

  for (int i = 0; i < N; i++) {
    for (int j = 0; j < M; j++) {
      tank[i][j] = H;
    }
  }

  for (int i = 0; i < N + 1; i++) {
    for (int j = 0; j < M; j++) {
      cin >> hor[i][j];
      if (hor[i][j] != -1) {
        if (i == 0) {
          tank[i][j] = min(tank[i][j], hor[i][j]);
          pq.push({hor[i][j], i, j});
        } else if (i == N) {
          tank[i - 1][j] = min(tank[i - 1][j], hor[i][j]);
          pq.push({hor[i][j], i - 1, j});
        }
      }
    }
  }

  for (int i = 0; i < N; i++) {
    for (int j = 0; j < M + 1; j++) {
      cin >> ver[i][j];
      if (ver[i][j] != -1) {
        if (j == 0) {
          tank[i][j] = min(tank[i][j], ver[i][j]);
          pq.push({ver[i][j], i, j});
        } else if (j == M) {
          tank[i][j - 1] = min(tank[i][j - 1], ver[i][j]);
          pq.push({ver[i][j], i, j - 1});
        }
      }
    }
  }

  while (!pq.empty()) {
    auto [cur_level, y, x] = pq.top();
    pq.pop();

    if (tank[y][x] != cur_level) continue;

    if (y > 0 && hor[y][x] != -1) {
      int next_level = max(cur_level, hor[y][x]);
      if (next_level < tank[y - 1][x]) {
        tank[y - 1][x] = next_level;
        pq.push({next_level, y - 1, x});
      }
    }

    if (y < N - 1 && hor[y + 1][x] != -1) {
      int next_level = max(cur_level, hor[y + 1][x]);
      if (next_level < tank[y + 1][x]) {
        tank[y + 1][x] = next_level;
        pq.push({next_level, y + 1, x});
      }
    }

    if (x > 0 && ver[y][x] != -1) {
      int next_level = max(cur_level, ver[y][x]);
      if (next_level < tank[y][x - 1]) {
        tank[y][x - 1] = next_level;
        pq.push({next_level, y, x - 1});
      }
    }

    if (x < M - 1 && ver[y][x + 1] != -1) {
      int next_level = max(cur_level, ver[y][x + 1]);
      if (next_level < tank[y][x + 1]) {
        tank[y][x + 1] = next_level;
        pq.push({next_level, y, x + 1});
      }
    }
  }

  long long ans = 0;
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < M; j++) {
      ans += tank[i][j];
    }
  }

  cout << ans << "\n";

  return 0;
}

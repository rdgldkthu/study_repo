#include <bits/stdc++.h>
using namespace std;

int N, M, T, x, d, k;
int a[55][55];
bool visited[55][55];
const int dy[4] = {-1, 0, 1, 0};
const int dx[4] = {0, 1, 0, -1};

void turn(int row, int d, int k) {
  vector<int> tmp(M);
  for (int i = 0; i < M; i++) tmp[i] = a[row][i];

  k %= M;
  if (d == 0) {
    for (int i = 0; i < M; i++) a[row][(i + k) % M] = tmp[i];
  } else {
    for (int i = 0; i < M; i++) a[row][(i - k + M) % M] = tmp[i];
  }
}

int main(int argc, char **argv) {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  cin >> N >> M >> T;
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < M; j++) cin >> a[i][j];
  }
  while (T--) {
    cin >> x >> d >> k;
    for (int i = x; i <= N; i += x) turn(i - 1, d, k);

    bool has_adj = false;
    vector<pair<int, int>> targets;
    for (int i = 0; i < N; i++) {
      for (int j = 0; j < M; j++) {
        if (a[i][j] == 0) continue;
        bool found = false;
        if (a[i][j] == a[i][(j + 1) % M]) found = true; // right
        if (a[i][j] == a[i][(j - 1 + M) % M]) found = true; // left
        if (i > 0 && a[i][j] == a[i - 1][j]) found = true; // up
        if (i < N - 1 && a[i][j] == a[i + 1][j]) found = true; // down
        if (found) {
          targets.push_back({i, j});
          has_adj = true;
        }
      }
    }
    if (has_adj) {
      for (auto p : targets) a[p.first][p.second] = 0;
    } else {
      double sum = 0;
      int count = 0;
      for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
          if (a[i][j] != 0) {
            sum += a[i][j];
            count++;
          }
        }
      }
      if (count > 0) {
        double avg = sum / count;
        for (int i = 0; i < N; i++) {
          for (int j = 0; j < M; j++) {
            if (a[i][j] == 0) continue;
            if ((double)a[i][j] > avg) a[i][j]--;
            else if ((double)a[i][j] < avg) a[i][j]++;
          }
        }
      }
    }
  }

  int ans = 0;
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < M; j++) {
      ans += a[i][j];
    }
  }

  cout << ans << '\n';

  return 0;
}
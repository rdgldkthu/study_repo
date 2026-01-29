#include <bits/stdc++.h>
using namespace std;

int N, x, y, d, g, cnt = 0;
int grid[101][101];
const int dy[]{0, -1, 0, 1};
const int dx[]{1, 0, -1, 0};
vector<int> dragon_curve[4][11];

void makeDragonCurve() {
  for (int i = 0; i < 4; i++) {
    dragon_curve[i][0].push_back(i);
    dragon_curve[i][1].push_back((i + 1) % 4);
    for (int j = 2; j <= 10; j++) {
      int n = dragon_curve[i][j - 1].size();
      for (int k = n - 1; k >= 0; k--) {
        dragon_curve[i][j].push_back((dragon_curve[i][j - 1][k] + 1) % 4);
      }
      for (int k = 0; k < n; k++) {
        dragon_curve[i][j].push_back(dragon_curve[i][j - 1][k]);
      }
    }
  }
}

void solve(int x, int y, int d, int g) {
  grid[y][x] = 1;
  for (int i = 0; i <= g; i++) {
    for (int dir : dragon_curve[d][i]) {
      x += dx[dir];
      y += dy[dir];
      grid[y][x] = 1;
    }
  }
}

int main(int argc, char **argv) {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  makeDragonCurve();

  cin >> N;
  for (int i = 0; i < N; i++) {
    cin >> x >> y >> d >> g;
    solve(x, y, d, g);
  }
  for (int i = 0; i < 100; i++) {
    for (int j = 0; j < 100; j++) {
      if (grid[i][j] && grid[i + 1][j] && grid[i][j + 1] && grid[i + 1][j + 1]) {
        cnt++;
      }
    }
  }

  cout << cnt << '\n';

  return 0;
}

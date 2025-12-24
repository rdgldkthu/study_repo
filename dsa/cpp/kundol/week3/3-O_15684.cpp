#include <bits/stdc++.h>

using namespace std;

int N, M, H, ans = 4;
int ladder[31][11];

bool check() {
  for (int start_col = 1; start_col <= N; start_col++) {
    int end_col = start_col;
    for (int row = 1; row <= H; row++) {
      int col_l = end_col - 1;
      int col_r = end_col;
      if (col_l >= 1 && ladder[row][col_l]) end_col--;
      if (col_r <= N && ladder[row][col_r]) end_col++;
    }
    if (start_col != end_col)
      return false;
  }
  return true;
}

void DFS(int cnt, int r, int c) {
  if (cnt >= ans) return;
  if (check()) {
    ans = cnt;
    return;
  }
  if (cnt == 3) return;
  for (int i = r; i <= H; i++) {
    for (int j = (i==r ? c : 1); j < N; j++) {
        if (ladder[i][j] || ladder[i][j-1] || ladder[i][j+1]) continue;
        ladder[i][j] = 1;
        DFS(cnt+1, i, j + 2);
        ladder[i][j] = 0;
    }
  }
}

int main(int argc, char **argv) {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  cin >> N >> M >> H;
  for (int i = 0; i < M; ++i) {
    int a, b; cin >> a >> b;
    ladder[a][b] = 1;
  }

  if (check()) {
    cout << 0 << '\n';
    return 0;
  }

  DFS(0, 1, 1);
  cout << (ans > 3 ? -1 : ans) << '\n';
  return 0;
}
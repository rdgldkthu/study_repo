#include <bits/stdc++.h>
using namespace std;

int N;
int house[16][16];
int dp[16][16][3];

int solve(int y, int x, int type) {
  if (y == N - 1 && x == N - 1) return 1;

  if (dp[y][x][type] != -1) return dp[y][x][type];

  dp[y][x][type] = 0;

  if (type == 0) { // horizontal
    if (x + 1 < N && house[y][x + 1] == 0) {
      dp[y][x][type] += solve(y, x + 1, 0);
    }
    if (y + 1 < N && x + 1 < N && house[y + 1][x] == 0 &&
        house[y][x + 1] == 0 && house[y + 1][x + 1] == 0) {
      dp[y][x][type] += solve(y + 1, x + 1, 2);
    }
  } else if (type == 1) { // vertical
    if (y + 1 < N && house[y + 1][x] == 0) {
      dp[y][x][type] += solve(y + 1, x , 1);
    }
    if (y + 1 < N && x + 1 < N && house[y + 1][x] == 0 &&
        house[y][x + 1] == 0 && house[y + 1][x + 1] == 0) {
      dp[y][x][type] += solve(y + 1, x + 1, 2);
    }
  } else { // diagonal
    if (x + 1 < N && house[y][x + 1] == 0) {
      dp[y][x][type] += solve(y, x + 1, 0);
    }
    if (y + 1 < N && house[y + 1][x] == 0) {
      dp[y][x][type] += solve(y + 1, x, 1);
    }
    if (y + 1 < N && x + 1 < N && house[y + 1][x] == 0 &&
        house[y][x + 1] == 0 && house[y + 1][x + 1] == 0) {
      dp[y][x][type] += solve(y + 1, x + 1, 2);
    }
  }

  return dp[y][x][type];
}

int main(int argc, char **argv) {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  cin >> N;

  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      cin >> house[i][j];
    }
  }

  memset(dp, -1, sizeof(dp));

  cout << solve(0, 1, 0) << endl;

  return 0;
}

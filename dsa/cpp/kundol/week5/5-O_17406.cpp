#include <bits/stdc++.h>
using namespace std;

enum Direction { UP, RIGHT, DOWN, LEFT };
int N, M, K, r, c, s, ans = INT_MAX;
int A[50][50], orders[6][3], used[6];
const int dy[] = {-1, 0, 1, 0};
const int dx[] = {0, 1, 0, -1};

void rotate(int r, int c, int s) {
  r--; c--;
  for (int i = 1; i <= s; i++) {
    int y = r - i;
    int x = c - i;
    int dir = RIGHT;
    int curr, prev = A[y][x];
    while (true) {
      int ny = y + dy[dir];
      int nx = x + dx[dir];
      curr = A[ny][nx];
      A[ny][nx] = prev;
      prev = curr;
      y = ny; x = nx;
      if (ny == r - i && nx == c - i) break;
      if (dir == RIGHT && nx == c + i) dir = DOWN;
      if (dir == DOWN && ny == r + i) dir = LEFT;
      if (dir == LEFT && nx == c - i) dir = UP;
    }
  }
}

int getValue() {
  int val = INT_MAX;
  for (int i = 0; i < N; i++) {
    int row_val = 0;
    for (int j = 0; j < M; j++) row_val += A[i][j];
    val = min(val, row_val);
  }
  return val;
}

void dfs(int cnt) {
  if (cnt == K) {
    ans = min(ans, getValue());
    return;
  }
  int temp[50][50];
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < M; j++) {
      temp[i][j] = A[i][j];
    }
  }
  for (int i = 0; i < K; i++) {
    if (used[i]) continue;
    rotate(orders[i][0], orders[i][1], orders[i][2]);
    used[i] = 1;
    dfs(cnt + 1);
    used[i] = 0;
    for (int i = 0; i < N; i++) {
      for (int j = 0; j < M; j++) {
        A[i][j] = temp[i][j];
      }
    }
  }
}

int main(int argc, char **argv) {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  cin >> N >> M >> K;

  for (int i = 0; i < N; i++) {
    for (int j = 0; j < M; j++) {
      cin >> A[i][j];
    }
  }

  for (int i = 0; i < K; i++) {
    cin >> r >> c >> s;
    orders[i][0] = r;
    orders[i][1] = c;
    orders[i][2] = s;
  }

  dfs(0);

  cout << ans << '\n';

  return 0;
}

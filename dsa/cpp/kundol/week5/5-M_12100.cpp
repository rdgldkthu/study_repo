#include <bits/stdc++.h>
using namespace std;

int N, ans = 0;
int a[20][20];

enum Direction { UP, DOWN, LEFT, RIGHT };

void tilt_board(int dir) {
    for (int i = 0; i < N; i++) {
        queue<int> q;
        int prev = 0;

        for (int j = 0; j < N; j++) {
            int y, x;
            if (dir == UP)    { y = j;     x = i; }
            if (dir == DOWN)  { y = N-1-j; x = i; }
            if (dir == LEFT)  { y = i;     x = j; }
            if (dir == RIGHT) { y = i;     x = N-1-j; }

            int curr = a[y][x];
            if (curr == 0) continue;

            if (prev == 0) {
                prev = curr;
            } else if (prev == curr) {
                q.push(prev * 2);
                prev = 0;
            } else {
                q.push(prev);
                prev = curr;
            }
        }
        if (prev != 0) q.push(prev);

        for (int j = 0; j < N; j++) {
            int y, x;
            if (dir == UP)    { y = j;     x = i; }
            if (dir == DOWN)  { y = N-1-j; x = i; }
            if (dir == LEFT)  { y = i;     x = j; }
            if (dir == RIGHT) { y = i;     x = N-1-j; }

            if (!q.empty()) {
                a[y][x] = q.front();
                q.pop();
            } else {
                a[y][x] = 0;
            }
        }
    }
}

void dfs(int cnt) {
  if (cnt == 5) {
    int biggest = 0;
    for (int y = 0; y < N; y++) {
      for (int x = 0; x < N; x++) {
        biggest = max(biggest, a[y][x]);
      }
    }
    ans = max(ans, biggest);
    return;
  }
  int temp[20][20];
  for (int y = 0; y < N; y++) {
    for (int x = 0; x < N; x++) {
      temp[y][x] = a[y][x];
    }
  }

  for (int dir = 0; dir < 4; dir++) {
    tilt_board(dir);
    dfs(cnt + 1);
    for (int y = 0; y < N; y++) {
      for (int x = 0; x < N; x++) {
        a[y][x] = temp[y][x];
      }
    }
  }
}

int main(int argc, char **argv) {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  cin >> N;

  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      cin >> a[i][j];
    }
  }

  dfs(0);

  cout << ans << '\n';

  return 0;
}

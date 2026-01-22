#include <bits/stdc++.h>
using namespace std;

int R, C, T, purifier;
int a[50][50], temp[50][50];
const int dy[4] = {-1, 0, 1, 0};
const int dx[4] = {0, 1, 0, -1};

void spread_dust() {
  fill(&temp[0][0], &temp[0][0] + 50 * 50, 0);
  for (int y = 0; y < R; y++) {
    for (int x = 0; x < C; x++) {
      if (a[y][x]) {
        int delta = a[y][x] / 5;
        for (int i = 0; i < 4; i++) {
          int ny = y + dy[i];
          int nx = x + dx[i];
          if (ny < 0 || ny >= R || nx < 0 || nx >= C) continue;
          if (a[ny][nx] == -1) continue;
          temp[ny][nx] += delta;
          temp[y][x] -= delta;
        }
      }
    }
  }
  for (int y = 0; y < R; y++) {
    for (int x = 0; x < C; x++) {
      a[y][x] += temp[y][x];
    }
  }
}

enum Direction { UP, RIGHT, DOWN, LEFT };

void purify_air() {
  // upper wind
  int y = purifier, x = 1;
  int curr, prev = 0;
  Direction direc = RIGHT;
  while (true) {
    curr = a[y][x];
    a[y][x] = prev;
    prev = curr;
    y += dy[direc];
    x += dx[direc];
    if (x == C) {
      y -= 1;
      x -= 1;
      direc = UP;
    } else if (y == -1) {
      y += 1;
      x -= 1;
      direc = LEFT;
    } else if (x == -1) {
      y += 1;
      x += 1;
      direc = DOWN;
    }
    if (y == purifier && x == 0) break;
  }

  // lower wind
  y = purifier + 1, x = 1;
  prev = 0;
  direc = RIGHT;
  while (true) {
    curr = a[y][x];
    a[y][x] = prev;
    prev = curr;
    y += dy[direc];
    x += dx[direc];
    if (x == C) {
      y += 1;
      x -= 1;
      direc = DOWN;
    } else if (y == R) {
      y -= 1;
      x -= 1;
      direc = LEFT;
    } else if (x == -1) {
      y -= 1;
      x += 1;
      direc = UP;
    }
    if (y == purifier + 1 && x == 0) break;
  }
}

int main(int argc, char **argv) {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  cin >> R >> C >> T;
  for (int i = 0; i < R; i++) {
    for (int j = 0; j < C; j++) {
      cin >> a[i][j];
      if (a[i][j] == -1 && purifier == 0) purifier = i;
    }
  }

  for (int i = 0; i < T; i++) {
    spread_dust();
    purify_air();
  }

  int ans = 2;
  for (int y = 0; y < R; y++) {
    for (int x = 0; x < C; x++) {
      ans += a[y][x];
    }
  }
  cout << ans << '\n';

  return 0;
}

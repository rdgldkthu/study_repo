#include <bits/stdc++.h>
using namespace std;

int R, C, M, ans = 0;
int sea[101][101], temp_sea[101][101];
int r[10001], c[10001], s[10001], d[10001] ,z[10001];
const int dy[] = {-1, 1, 0, 0};
const int dx[] = {0, 0, 1, -1};

void moveShark(int id) {
  int speed = s[id];
  int &dir = d[id];
  int &y = r[id], &x = c[id];

  if (dir < 2) speed %= (2 * (R - 1));
  else speed %= (2 * (C - 1));

  for(int step = 0; step < speed; step++) {
    if (dir == 0 && y == 1) dir = 1;
    if (dir == 1 && y == R) dir = 0;
    if (dir == 2 && x == C) dir = 3;
    if (dir == 3 && x == 1) dir = 2;
    y += dy[dir];
    x += dx[dir];
  }

  if (temp_sea[y][x]) {
    if (z[id] > z[temp_sea[y][x]]) {
      z[temp_sea[y][x]] = 0;
      temp_sea[y][x] = id;
    } else {
      z[id] = 0;
    }
  } else {
    temp_sea[y][x] = id;
  }
}

int main(int argc, char **argv) {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  cin >> R >> C >> M;

  if (M == 0) { cout << 0 << '\n'; return 0; }

  for (int i = 1; i <= M; i++) {
    cin >> r[i] >> c[i] >> s[i] >> d[i] >> z[i];
    d[i]--;
    sea[r[i]][c[i]] = i;
  }

  for (int i = 1; i <= C; i++) {
    for (int j = 1; j <= R; j++) {
      if (sea[j][i]) {
        ans += z[sea[j][i]];
        z[sea[j][i]] = 0;
        sea[j][i] = 0;
        break;
      }
    }
    fill(&temp_sea[0][0], &temp_sea[0][0] + 101 * 101, 0);
    for (int k = 1; k <= M; k++) {
      if (!z[k]) continue;
      moveShark(k);
    }
    memcpy(sea, temp_sea, sizeof(sea));
  }

  cout << ans << '\n';

  return 0;
}

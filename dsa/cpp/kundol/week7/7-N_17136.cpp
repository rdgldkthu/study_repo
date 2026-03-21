#include <bits/stdc++.h>
using namespace std;

int ans = 26;
int cnt[6];
int a[10][10];

bool placeable(int y, int x, int size) {
  if (y + size > 10 || x + size > 10) return false;
  for (int i = y; i < y + size; i++) {
    for (int j = x; j < x + size; j++) {
      if (a[i][j] == 0) return false;
    }
  }
  return true;
}

void editGrid(int y, int x, int size, int val) {
  for (int i = y; i < y + size; i++) {
    for (int j = x; j < x + size; j++) {
      a[i][j] = val;
    }
  }
}

void dfs(int y, int x) {
  if (accumulate(&a[0][0], &a[0][0] + 100, 0) == 0) {
    ans = min(ans, accumulate(&cnt[1], &cnt[1] + 5, 0));
    return;
  }
  if (y == 10) return;
  int ny, nx;
  if (x < 9) {
    ny = y;
    nx = x + 1;
  } else {
    ny = y + 1;
    nx = 0;
  }

  if (a[y][x] == 1) {
    for (int size = 5; size >= 1; size--) {
      if (placeable(y, x, size) && cnt[size] < 5) {
        editGrid(y, x, size, 0);
        cnt[size]++;
        dfs(ny, nx);
        editGrid(y, x, size, 1);
        cnt[size]--;
      }
    }
  } else {
    dfs(ny, nx);
  }
}

int main(int argc, char **argv) {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  for (int i = 0; i < 10; i++) {
    for (int j = 0; j < 10; j++) {
      cin >> a[i][j];
    }
  }

  dfs(0, 0);

  cout << (ans == 26 ? -1 : ans) << '\n';

  return 0;
}

#include <bits/stdc++.h>
using namespace std;

int N, s, l, ans = INT_MAX;
int a[20][20];

int countBits(int num) {
  int cnt = 0;
  for (int i = 1; i < (1 << N); i <<= 1) if (num & i) cnt++;
  return cnt;
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

  for (int i = 0; i < (1 << N); i++) {
    if (countBits(i) == N / 2) {
      s = 0; l = 0;
      for (int y = 0; y < N - 1; y++) {
        for (int x = y + 1; x < N; x++) {
          if (i & (1 << y) && i & (1 << x)) s += a[y][x] + a[x][y];
          else if (~i & (1 << y) && ~i & (1 << x)) l += a[y][x] + a[x][y];
        }
      }
      ans = min(ans, abs(s - l));
    }
  }

  cout << ans << '\n';

  return 0;
}

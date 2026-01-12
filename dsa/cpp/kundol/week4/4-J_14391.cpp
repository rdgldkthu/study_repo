#include <bits/stdc++.h>
using namespace std;

int N, M;
int a[4][4];

int main(int argc, char **argv) {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  cin >> N >> M;
  for (int i = 0; i < N; i++) {
    string s;
    cin >> s;
    for (int j = 0; j < M; j++) {
      a[i][j] = s[j] - '0';
    }
  }

  int ans = 0;
  for (int bm = 0; bm < (1 << N*M); bm++) {
    int total = 0;
    // horizontal (index bit 1)
    for (int y = 0; y < N; y++) {
      int cnt = 0;
      for (int x = 0; x < M; x++) {
        if (bm & (1 << (y * M + x))) {
          cnt = cnt * 10 + a[y][x];
        } else {
          total += cnt;
          cnt = 0;
          continue;
        }
      }
      total += cnt;
    }
    // vertical (index bit 0)
    for (int x = 0; x < M; x++) {
      int cnt = 0;
      for (int y = 0; y < N; y++) {
        if (bm & (1 << (y * M + x))) {
          total += cnt;
          cnt = 0;
          continue;
        } else {
          cnt = cnt * 10 + a[y][x];
        }
      }
      total += cnt;
    }
    ans = max(ans, total);
  }

  cout << ans << '\n';

  return 0;
}

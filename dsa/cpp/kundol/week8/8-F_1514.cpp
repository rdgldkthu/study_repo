#include <bits/stdc++.h>
using namespace std;

int N;
int curr[104], goal[104];
int dp[104][10][10][10];
const int INF = 1e9;
string start, pw;

int add_mod(int v, int t, int dir) {
  return (v + dir * t % 10 + 10) % 10;
};

int main(int argc, char **argv) {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  cin >> N;
  cin >> start;
  cin >> pw;
  for (int i = 0; i < N; i++) curr[i] = start[i] - '0';
  for (int i = 0; i < N; i++) goal[i] = pw[i] - '0';

  memset(dp, 0x3f, sizeof(dp));
  dp[0][curr[0]][curr[1]][curr[2]] = 0;

  for (int i = 0; i < N; i++) {
    for (int x = 0; x < 10; x++) {
      for (int y = 0; y < 10; y++) {
        for (int z = 0; z < 10; z++) {
          int now = dp[i][x][y][z];
          if (now >= INF) continue;
          for (int dir : {+1, -1}) {
            int d =
                (dir == +1) ? (goal[i] - x + 10) % 10 : (x - goal[i] + 10) % 10;

            for (int r3 = 0; r3 <= d; r3++) {
              for (int r2 = 0; r2 <= d - r3; r2++) {
                int r1 = d - r2 - r3;

                int ny = add_mod(y, r2 + r3, dir);
                int nz = add_mod(z, r3, dir);
                int nw = curr[i + 3];

                int c = (r1 + 2) / 3 + (r2 + 2) / 3 + (r3 + 2) / 3;
                dp[i + 1][ny][nz][nw] = min(dp[i + 1][ny][nz][nw], now + c);
              }
            }
          }
        }
      }
    }
  }

  cout << dp[N][0][0][0] << '\n';

  return 0;
}

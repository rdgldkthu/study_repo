#include <bits/stdc++.h>
using namespace std;

int N;
int STR[50], INT[50], PNT[50];
int dp[1001][1001];

int solve(int s, int i) {
  int &ret = dp[s][i];
  if (ret != -1) return ret;

  int cnt = 0, pnt = 0;

  for (int j = 0; j < N; j++) {
    if (s >= STR[j] || i >= INT[j]) {
      pnt += PNT[j];
      cnt++;
    }
  }

  if (cnt == N) return N;

  ret = cnt;

  int remain = pnt - (s + i - 2);

  if (remain > 0) {
    if (s < 1000) ret = max(ret, solve(s + 1, i));
    if (i < 1000) ret = max(ret, solve(s, i + 1));
  }

  return ret;
}

int main(int argc, char **argv) {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  memset(dp, -1, sizeof(dp));

  cin >> N;

  for (int i = 0; i < N; i++) cin >> STR[i] >> INT[i] >> PNT[i];

  cout << solve(1, 1) << '\n';

  return 0;
}

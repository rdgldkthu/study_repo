#include <bits/stdc++.h>
using namespace std;

int N;
long long dp[61][16][31];

long long solve(int day, int half, int full) {
  if (day > 2 * N) return 0;

  long long& res = dp[day][half][full];

  if (res != -1) return res;

  if (day == 2 * N) {
    res = 1;
  } else {
    res = 0;
    if (full > 0) res += solve(day + 1, half + 1, full - 1);
    if (half > 0) res += solve(day + 1, half - 1, full);
  }

  return res;
}

int main(int argc, char **argv) {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  while (true) {
    memset(dp, -1, sizeof(dp));
    cin >> N;

    if (N == 0) return 0;

    cout << solve(1, 0, N) << endl;
  }

  return 0;
}

#include <bits/stdc++.h>
using namespace std;

const int min_cost[] = {0, 0, 1, 7, 4, 2, 0, 8};
long long dp[101];

void solve_min() {
  for (int i = 1; i <= 100; i++) dp[i] = 1e18;

  dp[2] = 1; dp[3] = 7; dp[4] = 4; dp[5] = 2; dp[6] = 6; dp[7] = 8; dp[8] = 10;

  for (int i = 9; i <= 100; i++) {
    for (int j = 2; j <= 7; j++) {
      dp[i] = min(dp[i], dp[i - j] * 10 + min_cost[j]);
    }
  }
}

string solve_max(int num) {
  string res = "";
  if (num % 2) {
    res += '7';
    num -= 3;
  }
  while (num) {
    res += '1';
    num -= 2;
  }
  return res;
}

int main(int argc, char **argv) {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  solve_min();

  int n, num;
  cin >> n;
  while (n--) {
    cin >> num;
    cout << dp[num] << ' ' << solve_max(num) << '\n';
  }

  return 0;
}

#include <bits/stdc++.h>
using namespace std;

double pA, pB, ans;
double dp[19][19][19];

bool isPrime(int n) {
  if (n == 2 || n == 3 || n == 5 || n == 7 || n == 11 || n == 13 || n == 17) return true;
  return false;
}

int main(int argc, char **argv) {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  cin >> pA >> pB;

  pA /= 100.0;
  pB /= 100.0;

  dp[0][0][0] = 1.0;

  for (int i = 1; i <= 18; i++) {
    for (int a = 0; a <= i; a++) {
      for (int b = 0; b <= i; b++) {
        if (a <= 18 && b <= 18) dp[i][a][b] += dp[i - 1][a][b] * (1 - pA) * (1 - pB);
        if (a > 0) dp[i][a][b] += dp[i - 1][a - 1][b] * pA * (1 - pB);
        if (b > 0) dp[i][a][b] += dp[i - 1][a][b - 1] * (1 - pA) * pB;
        if (a > 0 && b > 0) dp[i][a][b] += dp[i - 1][a - 1][b - 1] * pA * pB;
      }
    }
  }

  for (int i = 0; i <= 18; i++) {
    for (int j = 0; j <= 18; j++) {
      if (isPrime(i) || isPrime(j)) ans += dp[18][i][j];
    }
  }

  cout << fixed << setprecision(16) << ans << endl;

  return 0;
}

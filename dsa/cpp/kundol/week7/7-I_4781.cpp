#include <bits/stdc++.h>
using namespace std;

int n, c;
double m, p;
int dp[10001];

int main(int argc, char **argv) {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  while (true) {
    cin >> n >> m;
    if (n == 0 && m == 0.00) break;
    int mm = (int)(100 * m + 0.5);
    for (int i = 0; i <= mm; i++) dp[i] = 0;
    for (int i = 0; i < n; i++) {
      cin >> c >> p;
      int pp = (int)(100 * p + 0.5);
      for (int j = pp; j <= mm; j++) dp[j] = max(dp[j], dp[j - pp] + c);
    }
    cout << dp[mm] << '\n';
  }

  return 0;
}

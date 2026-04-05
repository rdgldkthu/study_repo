#include <bits/stdc++.h>
using namespace std;

int dp[100005]; // length
const string messi1 = "Messi";
const string messi2 = "Messi Gimossi";

char solve(int N, int idx) {
  if (N == 1) return messi1[idx - 1];
  if (N == 2) return messi2[idx - 1];
  if (idx == dp[N - 1]) return 'i';
  if (idx < dp[N - 1]) return solve(N - 1, idx);
  if (idx == dp[N - 1] + 1) return ' ';
  if (idx > dp[N - 1] + 1) return solve(N - 2, idx - dp[N - 1] - 1);
  return ' ';
}

int main(int argc, char **argv) {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int M; cin >> M;

  dp[1] = 5;
  dp[2] = 13;
  int i = 3;
  while (true) {
    dp[i] = dp[i - 1] + dp[i - 2] + 1;
    if (dp[i] > M) break;
    i++;
  }

  char ans = solve(i, M);
  if (ans != ' ') cout << ans << '\n';
  else cout << "Messi Messi Gimossi\n";

  return 0;
}

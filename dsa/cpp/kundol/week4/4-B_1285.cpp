#include <bits/stdc++.h>

using namespace std;

int a[20];
int N, ans = 20 * 20;

void solve(int id) {
  int cnt = 0;
  for (int y = 1; y < (1 << N); y <<= 1) {
    int temp = 0;
    for (int x = 0; x < N; x++)
      if (a[x] & y) temp += 1;
    cnt += min(temp, N-temp);
  }
  ans = min(ans, cnt);
  if (id + 1 == N) return;
  solve(id + 1);
  a[id] = ~a[id];
  solve(id + 1);
  a[id] = ~a[id];
}

int main(int argc, char **argv) {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  cin >> N;
  for (int i = 0; i < N; i++) {
    string s; cin >> s;
    int value = 1;
    for (int j = 0; j < N; j++) {
      if (s[j] == 'T') a[i] |= value;
      value *= 2;
    }
  }

  solve(0);

  cout << ans << endl;

  return 0;
}
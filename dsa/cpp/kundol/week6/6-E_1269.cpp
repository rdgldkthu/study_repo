#include <bits/stdc++.h>
using namespace std;

int main(int argc, char **argv) {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int N, M;
  cin >> N >> M;

  vector<int> A(N), B(M);
  for (int i = 0; i < N; i++) cin >> A[i];
  for (int i = 0; i < M; i++) cin >> B[i];

  map<int, int> m;

  for (int a : A) {
    m[a]++;
  }

  for (int b : B) {
    if (m[b] > 0) m[b] = -1;
    else m[b]++;
  }

  int ans = 0;
  for (auto& [k,v] : m) {
    if (v != -1) ans += v;
  }

  cout << ans << '\n';

  return 0;
}

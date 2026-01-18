#include <bits/stdc++.h>
using namespace std;

int main(int argc, char **argv) {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int N; cin >> N;
  vector<pair<int, int>> v(N);
  for (int i = 0; i < N; i++) cin >> v[i].second >> v[i].first;

  sort(v.begin(), v.end());

  int ans = 0, prev = 0;
  for (auto &[end, start] : v) {
    if (start >= prev) {
      prev = end;
      ans++;
    }
  }

  cout << ans << '\n';


  return 0;
}

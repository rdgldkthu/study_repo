#include <bits/stdc++.h>
using namespace std;

int main(int argc, char **argv) {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int N; cin >> N;
  vector<pair<int, int>> v(N); // arrival, inspection
  for (int i = 0; i < N; i++) cin >> v[i].first >> v[i].second;

  sort(v.begin(), v.end());

  long long ans = 0;

  for (auto &cow : v) {
    ans = ans > cow.first ? ans : cow.first;
    ans += cow.second;
  }

  cout << ans << '\n';

  return 0;
}

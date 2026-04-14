#include <bits/stdc++.h>
using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int N;
  cin >> N;

  vector<pair<int ,int>> v(N);
  for (int i = 0; i < N; i++) {
    cin >> v[i].second >> v[i].first;
  }

  sort(v.begin(), v.end());

  for (auto [y, x] : v) {
    cout << x << " " << y << '\n';
  }

  return 0;
}

#include <bits/stdc++.h>
using namespace std;

int main(int argc, char **argv) {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int N; cin >> N;

  vector<pair<int, int>> v(N);

  for (int i = 0; i < N; i++) cin >> v[i].first >> v[i].second;

  sort(v.begin(), v.end());

  vector<int> lis;

  for (int i = 0; i < N; i++) {
    int num = v[i].second;
    if (lis.empty() || lis.back() < num) {
      lis.push_back(num);
    } else {
      auto pos = lower_bound(lis.begin(), lis.end(), num);
      *pos = num;
    }
  }

  cout << N - lis.size() << '\n';

  return 0;
}

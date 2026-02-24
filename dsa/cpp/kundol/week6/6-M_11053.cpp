#include <bits/stdc++.h>
using namespace std;

int main(int argc, char **argv) {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int N, ans = 0;
  cin >> N;

  vector<int> v(N), lis;
  for (int i = 0; i < N; i++) cin >> v[i];

  for (int i = 0; i < N; i++) {
    if (lis.empty() || lis.back() < v[i]) {
      lis.push_back(v[i]);
    } else {
      auto pos = lower_bound(lis.begin(), lis.end(), v[i]);
      *pos = v[i];
    }
  }

  cout << lis.size() << '\n';

  return 0;
}

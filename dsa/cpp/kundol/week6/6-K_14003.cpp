#include <bits/stdc++.h>
using namespace std;

int main(int argc, char **argv) {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int N; cin >> N;
  vector<int> v(N), pos(N), lis;

  for (int i = 0; i < N; i++) {
    cin >> v[i];
    if (lis.empty() || lis.back() < v[i]) {
      pos[i] = lis.size();
      lis.push_back(v[i]);
    } else {
      auto it = lower_bound(lis.begin(), lis.end(), v[i]);
      *it = v[i];
      pos[i] = distance(lis.begin(), it);
    }
  }

  cout << lis.size() << '\n';

  vector<int> ans;
  int target = lis.size() - 1;
  for (int i = N - 1; i >= 0; i--) {
    if (pos[i] == target) {
      ans.push_back(v[i]);
      target--;
    }
  }

  for (int i = ans.size() - 1; i >= 0; i--) cout << ans[i] << ' ';
  cout << '\n';

  return 0;
}

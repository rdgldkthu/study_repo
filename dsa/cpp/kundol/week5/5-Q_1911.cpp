#include <bits/stdc++.h>
using namespace std;

int N, L, a, b, start, gap, cnt, ans = 0, prev_end = -1;
vector<pair<int, int>> v;

int main(int argc, char **argv) {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  cin >> N >> L;
  for (int i = 0; i < N; i++) {
    cin >> a >> b;
    v.push_back({a, b});
  }

  sort(v.begin(), v.end());

  for (auto &[l, r] : v) {
    if (prev_end >= r) continue;
    start = max(l, prev_end);
    gap = r - start;
    cnt = gap / L + (gap % L != 0);
    ans += cnt;
    prev_end = start + cnt * L;
  }

  cout << ans << '\n';

  return 0;
}

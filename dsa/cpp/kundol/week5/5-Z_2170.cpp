#include <bits/stdc++.h>
using namespace std;

int main(int argc, char **argv) {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int N;
  cin >> N;

  vector<pair<long long, long long>> lines(N);
  for (int i = 0; i < N; i++) cin >> lines[i].first >> lines[i].second;

  sort(lines.begin(), lines.end());

  long long ans = 0;
  long long cur_l = lines[0].first, cur_r = lines[0].second;
  for (int i = 1; i < N; i++) {
    long long next_l = lines[i].first;
    long long next_r = lines[i].second;
    if (next_l <= cur_r) {
      cur_r = max(cur_r, next_r);
    } else {
      ans += cur_r - cur_l;
      cur_l = next_l;
      cur_r = next_r;
    }
  }
  ans += cur_r - cur_l;

  cout << ans << '\n';

  return 0;
}

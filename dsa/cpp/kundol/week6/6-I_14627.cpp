#include <bits/stdc++.h>
using namespace std;

int S, C;
vector<long long> v;

bool solve(long long mid) {
  long long cnt = 0;
  for (int i = 0; i < S; i++) cnt += v[i] / mid;
  return cnt >= C;
}

int main(int argc, char **argv) {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  cin >> S >> C;
  v.resize(S);

  long long l = 1, r = 1, total = 0;
  for (int i = 0; i < S; i++) {
    cin >> v[i];
    r = max(r, v[i]);
    total += v[i];
  }

  long long len;
  while (l <= r) {
    long long mid = (l + r) / 2;
    if (solve(mid)) {
      len = mid;
      l = mid + 1;
    } else {
      r = mid - 1;
    }
  }

  cout << total - len * C << '\n';

  return 0;
}

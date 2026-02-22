#include <bits/stdc++.h>
using namespace std;

int N, M, l = 0, r = 0, ans;
vector<int> v;

bool solve(int mid) {
  int balance = mid, cnt = 1;
  for (int i = 0; i < N; i++) {
    if (v[i] <= balance) {
      balance -= v[i];
    } else {
      balance = mid - v[i];
      cnt++;
    }
  }
  return cnt <= M;
}

int main(int argc, char **argv) {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  cin >> N >> M;

  v.resize(N);
  for (int i = 0; i < N; i++) {
    cin >> v[i];
    l = max(l, v[i]);
    r += v[i];
  }

  ans = r;
  while (l <= r) {
    int mid = (l + r) / 2;
    if (solve(mid)) {
      ans = mid;
      r = mid - 1;
    } else {
      l = mid + 1;
    }
  }

  cout << ans << '\n';

  return 0;
}

#include <bits/stdc++.h>
using namespace std;

long long X, Y, l = 1, r = 1'000'000'000;

int main(int argc, char **argv) {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  cin >> X >> Y;

  if (X == Y) {
    cout << -1 << '\n';
    return 0;
  }

  long long mid, ans = r;
  while (l <= r) {
    mid = (l + r) / 2;
    if ((Y * 100 / X) < ((Y + mid) * 100 / (X + mid))) {
      ans = mid;
      r = mid - 1;
    } else {
      l = mid + 1;
    }
  }

  if (ans == r) cout << -1 << '\n';
  else cout << ans << '\n';

  return 0;
}

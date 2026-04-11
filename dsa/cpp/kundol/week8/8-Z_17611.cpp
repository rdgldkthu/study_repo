#include <bits/stdc++.h>
using namespace std;

int main(int argc, char **argv) {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int n;
  cin >> n;

  vector<pair<int, int>> p(n);
  for (int i = 0; i < n; i++) {
    cin >> p[i].first >> p[i].second;
  }

  const int OFFSET = 500000;
  const int MAX_COOR = 1000001;

  vector<int> sy(MAX_COOR + 1, 0), sx(MAX_COOR + 1, 0);
  for (int i = 0; i < n; i++) {
    auto [x1, y1] = p[i];
    auto [x2, y2] = p[(i + 1) % n];

    if (x1 == x2) {
      int a = min(y1, y2) + OFFSET;
      int b = max(y1, y2) + OFFSET;
      sy[a]++;
      sy[b]--;
    } else {
      int a = min(x1, x2) + OFFSET;
      int b = max(x1, x2) + OFFSET;
      sx[a]++;
      sx[b]--;
    }
  }

  int ans = 0, cur = 0;
  for (int i = 0; i <= MAX_COOR; i++) {
    cur += sy[i];
    ans = max(ans, cur);
  }

  cur = 0;
  for (int i = 0; i <= MAX_COOR; i++) {
    cur += sx[i];
    ans = max(ans, cur);
  }

  cout << ans << "\n";

  return 0;
}

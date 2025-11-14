#include <bits/stdc++.h>

using namespace std;

int main(int argc, char **argv) {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  int N, M, J;
  cin >> N >> M;
  cin >> J;

  int ans = 0;
  int cur_pos = 1;

  while (J--) {
    int apple;
    cin >> apple;
    if (cur_pos <= apple && apple < cur_pos + M)
      continue;
    if (apple < cur_pos) {
      int dist = cur_pos - apple;
      ans += dist;
      cur_pos -= dist;
    }
    if (apple >= cur_pos + M) {
      int dist = apple - cur_pos - M + 1;
      ans += dist;
      cur_pos += dist;
    }
  }
  cout << ans << '\n';
  return 0;
}
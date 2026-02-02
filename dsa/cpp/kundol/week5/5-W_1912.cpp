#include <bits/stdc++.h>
using namespace std;

int main(int argc, char **argv) {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int n; cin >> n;

  int curr = 0;
  int ans = INT_MIN;

  for (int i = 0; i < n; i++) {
    int num; cin >> num;
    curr = max(num, curr + num);
    ans = max(ans, curr);
  }

  cout << ans << '\n';

  return 0;
}

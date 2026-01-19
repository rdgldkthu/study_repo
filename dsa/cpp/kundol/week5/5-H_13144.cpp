#include <bits/stdc++.h>
using namespace std;

int main(int argc, char **argv) {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  long long N; cin >> N;

  long long arr[100001];
  for (int i = 0; i < N; i++) cin >> arr[i];

  long long ans = 0;
  long long l = 0, r = 0;
  long long cnt[100001] = {0};
  while (r < N) {
    if (!cnt[arr[r]]) {
      cnt[arr[r]]++;
      r++;
    } else {
      ans += (r - l);
      cnt[arr[l]]--;
      l++;
    }
  }
  ans += (r - l) * (r - l + 1) / 2;
  cout << ans << '\n';

  return 0;
}

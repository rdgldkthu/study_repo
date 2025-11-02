#include <bits/stdc++.h>

using namespace std;

int main(int argc, char **argv) {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  int N, K;
  cin >> N >> K;

  int temperatures[100'000];
  for (int i = 0; i < N; ++i) cin >> temperatures[i];

  int ans = -100 * 100'000, sum = 0, length = 0;
  for (int i = 0; i < N; ++i) {
    sum += temperatures[i];
    length++;
    if (length == K) {
        ans = max(ans, sum);
        sum -= temperatures[i-K+1];
        length--;
    }
  }

  cout << ans << '\n';

  return 0;
}
#include <bits/stdc++.h>

using namespace std;

int main(int argc, char **argv) {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  int T;
  cin >> T;

  while (T--) {
    long long N, cnt = 0;
    cin >> N;

    while (N > 0) {
        N /= 5;
        cnt += N;
    }

    cout << cnt << '\n';
  }

  return 0;
}
#include <bits/stdc++.h>
using namespace std;

int main(int argc, char **argv) {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int N;
  cin >> N;

  vector<bool> prime(N + 1, true);
  prime[0] = prime[1] = false;
  for (int p = 2; p * p <= N; p++) {
    if (prime[p]) {
      for (int i = p * p; i <= N; i += p) {
        prime[i] = false;
      }
    }
  }

  vector<int> prime_lut;
  for (int p = 2; p <= N; p++) {
    if (prime[p]) {
      prime_lut.push_back(p);
    }
  }

  int window = 0, cnt = 0;
  int l = 0, r = 0;
  int M = prime_lut.size();
  while (true) {
    if (window >= N) {
      if (window == N)
        cnt++;
      window -= prime_lut[l++];
    } else if (r == M) {
      break;
    } else {
      window += prime_lut[r++];
    }
  }

  cout << cnt << '\n';

  return 0;
}

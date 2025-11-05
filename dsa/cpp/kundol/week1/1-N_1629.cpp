#include <bits/stdc++.h>

using namespace std;

long long modpow(long long a, long long b, long long c) {
  long long result = 1;
  a %= c;
  while (b > 0) {
    if (b & 1)
      result = (result * a) % c;
    a = (a * a) % c;
    b >>= 1;
  }
  return result;
}

int main(int argc, char **argv) {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  int A, B, C;
  cin >> A >> B >> C;

  cout << modpow(A, B, C) << '\n';

  return 0;
}

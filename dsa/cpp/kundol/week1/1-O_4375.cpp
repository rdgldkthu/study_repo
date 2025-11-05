#include <bits/stdc++.h>

using namespace std;

int main(int argc, char **argv) {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  int n;
  while (cin >> n) {
    int cnt = 1;
    long long ones = 1;

    while (ones % n != 0) {
      ++cnt;
      ones = ones * 10 + 1;
      ones %= n;
    }

    cout << cnt << '\n';
  }

  return 0;
}

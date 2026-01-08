#include <bits/stdc++.h>

using namespace std;

int main(int argc, char **argv) {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int X;
  cin >> X;

  int cnt = 0;
  for (int i = 1; i < (1 << 7); i <<= 1) {
    if (i & X) cnt++;
  }

  cout << cnt << '\n';

  return 0;
}
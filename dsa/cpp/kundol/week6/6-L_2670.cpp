#include <bits/stdc++.h>
using namespace std;

int main(int argc, char **argv) {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int N; cin >> N;

  double prod = 1, num, ans = 0;

  for (int i = 0; i < N; i++) {
    cin >> num;
    if (prod * num > num) prod *= num;
    else prod = num;
    ans = max(ans, prod);
  }

  cout << fixed << setprecision(3) << ans << '\n';

  return 0;
}

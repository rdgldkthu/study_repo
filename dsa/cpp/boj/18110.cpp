#include <bits/stdc++.h>
using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int n;
  cin >> n;

  if (n == 0) {
    cout << 0 << "\n";
    return 0;
  }

  int skip = round(float(n) * 0.15f);

  vector<int> v(n);
  for (int i = 0; i < n; i++) {
    cin >> v[i];
  }

  sort(v.begin(), v.end());

  int total = 0;
  for (int i = skip; i < n - skip; i++) {
    total += v[i];
  }

  cout << round(float(total) / (n - 2 * skip)) << "\n";

  return 0;
}

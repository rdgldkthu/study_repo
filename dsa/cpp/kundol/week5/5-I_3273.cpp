#include <bits/stdc++.h>
using namespace std;

int main(int argc, char **argv) {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int n, x;
  vector<int> v;
  cin >> n;
  for (int i = 0; i < n; i++) {
    int num; cin >> num;
    v.push_back(num);
  }
  cin >> x;

  sort(v.begin(), v.end());

  int cnt = 0;
  int l = 0, r = n - 1;

  while (l!=r) {
    int sum = v[l] + v[r];
    if (sum == x) {
      cnt++;
      l++;
    }
    else if (sum > x) r--;
    else if (sum < x) l++;
  }

  cout << cnt << '\n';

  return 0;
}

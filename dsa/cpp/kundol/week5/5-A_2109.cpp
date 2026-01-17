#include <bits/stdc++.h>
using namespace std;

int main(int argc, char **argv) {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int n;
  cin >> n;
  if (n==0) {
    cout << 0 << '\n';
    return 0;
  }

  vector<pair<int, int>> v(n);
  for (int i = 0; i < n; i++) {
    cin >> v[i].second >> v[i].first;
  }

  sort(v.begin(), v.end());

  priority_queue<int, vector<int>, greater<int>> pq;

  for (int i = 0; i < n; i++) {
    pq.push(v[i].second);
    if (pq.size() > v[i].first) pq.pop();
  }

  int ans = 0;
  while (!pq.empty()) {
    ans += pq.top();
    pq.pop();
  }

  cout << ans << '\n';

  return 0;
}

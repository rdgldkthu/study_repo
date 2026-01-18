#include <bits/stdc++.h>
using namespace std;

int main(int argc, char **argv) {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int N;
  cin >> N;

  vector<pair<int,int>> v(N); // ddl, cost
  for (int i = 0; i < N; i++) cin >> v[i].first >> v[i].second;

  sort(v.begin(), v.end());

  priority_queue<int, vector<int>, greater<int>> pq;

  for (int i = 0; i < N; i++) {
      pq.push(v[i].second);
      if (pq.size() > v[i].first) pq.pop();
    }

  long long ans = 0;
  while (!pq.empty()) {
    ans += pq.top();
    pq.pop();
  }

  cout << ans << '\n';

  return 0;
}

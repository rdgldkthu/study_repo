#include <bits/stdc++.h>
using namespace std;

int main(int argc, char **argv) {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int N, K; cin >> N >> K;
  vector<pair<int, int>> gems(N); // weight, value
  for (int i = 0; i < N; i++) cin >> gems[i].first >> gems[i].second;
  vector<int> bags(K);
  for (int i = 0; i < K; i++) cin >> bags[i];

  sort(gems.begin(), gems.end());
  sort(bags.begin(), bags.end());

  priority_queue<int> pq;
  long long ans = 0;
  int gem_id = 0;
  for (int i = 0; i < K; i++) {
    while (gem_id < N && gems[gem_id].first <= bags[i])
      pq.push(gems[gem_id++].second);
    if (!pq.empty()) {
      ans += pq.top();
      pq.pop();
    }
  }

  cout << ans << '\n';

  return 0;
}

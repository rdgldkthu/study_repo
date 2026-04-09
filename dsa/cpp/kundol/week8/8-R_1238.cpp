#include <bits/stdc++.h>
using namespace std;
using pii = pair<int, int>;

void dijkstra(vector<pii> adj[], vector<int>& time, int start) {
  priority_queue<pii, vector<pii>, greater<pii>> pq;
  time[start] = 0;
  pq.push({0, start});

  while (!pq.empty()) {
    int u = pq.top().second;
    int u_time = pq.top().first;
    pq.pop();

    if (u_time != time[u]) continue;

    for (auto &[v, v_time] : adj[u]) {
      int total_time = u_time + v_time;
      if (total_time < time[v]) {
        time[v] = total_time;
        pq.push({total_time, v});
      }
    }
  }
}

int main(int argc, char **argv) {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int N, M, X;
  cin >> N >> M >> X;

  vector<pii> adj[1001], radj[1001];
  for (int i = 0; i < M; i++) {
    int a, b, t;
    cin >> a >> b >> t;
    adj[a].push_back({b, t});
    radj[b].push_back({a, t});
  }

  const int INF = 1e9;
  vector<int> time_from(N + 1, INF), time_to(N + 1, INF);

  dijkstra(adj, time_from, X);
  dijkstra(radj, time_to, X);

  int ans = 0;
  for (int i = 1; i <= N; i++) ans = max(ans, time_to[i] + time_from[i]);
  cout << ans << '\n';

  return 0;
}

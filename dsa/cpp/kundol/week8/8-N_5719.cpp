#include <bits/stdc++.h>
using namespace std;

const int INF = 1e9;
vector<int> dist(500, INF);
vector<pair<int,int>> adj[500], radj[500];
int visited[500];
int removed[500][500];

void dijkstra(int start, bool rem = false) {
  fill(dist.begin(), dist.end(), INF);
  priority_queue<pair<int, int>, vector<pair<int,int>>, greater<pair<int, int>>> pq;
  dist[start] = 0;
  pq.push({0, start});
  while (!pq.empty()) {
    int u_cost = pq.top().first;
    int u = pq.top().second;
    pq.pop();

    if (dist[u] != u_cost) continue;

    for(auto &[v, v_weight] : adj[u]) {
      if (rem && removed[u][v]) continue;
      int total_cost = u_cost + v_weight;
      if (total_cost < dist[v]) {
        dist[v] = total_cost;
        pq.push({total_cost, v});
      }
    }
  }
}

void dfs(int to) {
  if (visited[to]) return;
  visited[to] = true;
  for (auto &[from, cost] : radj[to]) {
    if (dist[from] + cost == dist[to]) {
      removed[from][to] = 1;
      dfs(from);
    }
  }
}

int main(int argc, char **argv) {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  while (true) {
    int N, M;
    cin >> N >> M;
    if (N == 0 &&  M == 0) break;

    for (int i = 0; i < N; i++) {
      adj[i].clear();
      radj[i].clear();
    }

    memset(visited, 0, sizeof(visited));
    memset(removed, 0, sizeof(removed));

    int S, D;
    cin >> S >> D;

    for (int i = 0; i < M; i++) {
      int U, V, P;
      cin >> U >> V >> P;
      adj[U].push_back({V, P});
      radj[V].push_back({U, P});
    }

    dijkstra(S);
    if (dist[D] != INF) dfs(D);
    dijkstra(S, true);

    if (dist[D] == INF) cout << -1 << '\n';
    else cout << dist[D] << '\n';
  }

  return 0;
}

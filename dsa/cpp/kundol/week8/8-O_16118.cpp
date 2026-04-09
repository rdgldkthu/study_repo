#include <bits/stdc++.h>
using namespace std;
using pii = pair<int, int>;
using tiii = tuple<int, int, int>;

int N, M;
const int INF = 1e9;
vector<pii> adj[4001];
vector<int> fox_dist, wolf_dist[2];

void fox(int start) {
  fox_dist.resize(4001);
  fill(fox_dist.begin(), fox_dist.end(), INF);
  priority_queue<pii, vector<pii>, greater<pii>> pq;
  fox_dist[start] = 0;
  pq.push({0, start});

  while (!pq.empty()) {
    int u_cost = pq.top().first;
    int u = pq.top().second;
    pq.pop();

    if (u_cost != fox_dist[u]) continue;

    for (auto &[v, v_weight] : adj[u]) {
      int total_cost = u_cost + v_weight;
      if (total_cost < fox_dist[v]) {
        fox_dist[v] = total_cost;
        pq.push({total_cost, v});
      }
    }
  }
}

void wolf(int start) {
  wolf_dist[0].resize(4001);
  wolf_dist[1].resize(4001);
  fill(wolf_dist[0].begin(), wolf_dist[0].end(), INF);
  fill(wolf_dist[1].begin(), wolf_dist[1].end(), INF);
  priority_queue<tiii, vector<tiii>, greater<tiii>> pq;
  wolf_dist[0][start] = 0;
  pq.push({0, start, 0});

  while (!pq.empty()) {
    int u_cost = get<0>(pq.top());
    int u = get<1>(pq.top());
    int flag = get<2>(pq.top());
    pq.pop();

    if (u_cost != wolf_dist[flag][u]) continue;

    for (auto [v, v_weight] : adj[u]) {
      if (flag == 0) v_weight /= 2;
      else v_weight *= 2;
      int total_cost = u_cost + v_weight;
      if (total_cost < wolf_dist[flag^1][v]) {
        wolf_dist[flag^1][v] = total_cost;
        pq.push({total_cost, v, flag^1});
      }
    }
  }
}

int main(int argc, char **argv) {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  cin >> N >> M;

  for (int i = 0; i < M; i++) {
    int a, b, d;
    cin >> a >> b >> d;
    adj[a].push_back({b, 2 * d});
    adj[b].push_back({a, 2 * d});
  }

  fox(1);
  wolf(1);

  int ans = 0;
  for (int i = 2; i <= N; i++) {
    if (fox_dist[i] < min(wolf_dist[0][i], wolf_dist[1][i])) ans++;
  }

  cout << ans << '\n';

  return 0;
}

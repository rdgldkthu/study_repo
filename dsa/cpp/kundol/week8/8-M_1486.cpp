#include <bits/stdc++.h>
using namespace std;

void dijkstra(vector<pair<int, int>> adj[], vector<int> &dist, int start) {
  priority_queue<pair<int, int>, vector<pair<int, int>>,
                 greater<pair<int, int>>> pq;
  dist[start] = 0;
  pq.push({0, start});

  while (!pq.empty()) {
    int u_cost = pq.top().first;
    int u = pq.top().second;
    pq.pop();

    if (dist[u] != u_cost) continue;

    for (auto &[v, v_weight] : adj[u]) {
      int total_cost = u_cost + v_weight;
      if (total_cost < dist[v]) {
        dist[v] = total_cost;
        pq.push({total_cost, v});
      }
    }
  }
}

int main(int argc, char **argv) {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  map<char, int> height;
  for (int i = 0; i < 26; i++) {
    height.insert({'A' + i, i});
    height.insert({'a' + i, i + 26});
  }

  int N, M, T, D;
  cin >> N >> M >> T >> D;

  int mountain[25][25];
  for (int i = 0; i < N; i++) {
    string row;
    cin >> row;
    for (int j = 0; j < M; j++) {
      mountain[i][j] = height[row[j]];
    }
  }

  const int INF = 1e9;
  const int dy[] = {-1, 0, 1, 0};
  const int dx[] = {0, 1, 0, -1};
  vector<pair<int, int>> adj[625], radj[625];
  vector<int> dist(625, INF), rdist(625, INF);
  for (int y = 0; y < N; y++) {
    for (int x = 0; x < M; x++) {
      int u_id = y * M + x;
      int u_height = mountain[y][x];

      for (int i = 0; i < 4; i++) {
        int ny = y + dy[i];
        int nx = x + dx[i];

        if (ny < 0 || ny >= N || nx < 0 || nx >= M) continue;

        int v_id = ny * M + nx;
        int v_height = mountain[ny][nx];

        if (abs(u_height - v_height) > T) continue;

        if (u_height >= v_height) {
          adj[u_id].push_back({v_id, 1});
          radj[v_id].push_back({u_id, 1});
        } else {
          int dif = v_height - u_height;
          adj[u_id].push_back({v_id, dif * dif});
          radj[v_id].push_back({u_id, dif * dif});
        }
      }
    }
  }

  dijkstra(adj, dist, 0);
  dijkstra(radj, rdist, 0);

  int ans = mountain[0][0];
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < M; j++) {
      int id = i * M + j;
      if (dist[id] == INF || rdist[id] == INF) continue;
      if (dist[id] + rdist[id] <= D) ans = max(ans, mountain[i][j]);
    }
  }

  cout << ans << '\n';

  return 0;
}

#include <bits/stdc++.h>
using namespace std;
using pii = pair<int, int>;

void dijkstra(vector<pii> adj[], vector<int> &dist, int start) {
  priority_queue<pii, vector<pii>, greater<pii>> pq;
  dist[start] = 0;
  pq.push({0, start});

  while (!pq.empty()) {
    int u = pq.top().second;
    int u_traveled = pq.top().first;
    pq.pop();

    if (u_traveled != dist[u]) continue;

    for (auto &[v, v_dist] : adj[u]) {
      int total_traveled = u_traveled + v_dist;
      if (total_traveled < dist[v]) {
        dist[v] = total_traveled;
        pq.push({total_traveled, v});
      }
    }
  }
}

int main(int argc, char **argv) {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  const int INF = 1e9;

  int tc;
  cin >>tc;

  while (tc--) {
    int n, m, t;
    cin >> n >> m >> t;

    int s, g, h;
    cin >> s >> g >> h;

    vector<pii> adj[2001];
    for (int i = 0; i < m; i++) {
      int a, b, d;
      cin >> a >> b >> d;
      adj[a].push_back({b, d});
      adj[b].push_back({a, d});
    }

    vector<int> dist(n + 1, INF);
    dijkstra(adj, dist, s);

    vector<int> possible_dest;
    for (int i = 0; i < t; i++) {
      int x;
      cin >> x;

      vector<bool> visited(n + 1, false);
      queue<int> q;
      bool pass_gh = false;

      visited[x] = true;
      q.push(x);

      while (!q.empty() && !pass_gh) {
        int curr = q.front();
        q.pop();

        for (auto &[next, next_dist] : adj[curr]) {
          if (dist[next] + next_dist != dist[curr]) continue;
          if ((curr == g && next == h) || (curr == h && next == g)) {
            possible_dest.push_back(x);
            pass_gh = true;
            break;
          }
          if (visited[next]) continue;
          visited[next] = true;
          q.push(next);
        }
      }
    }

    sort(possible_dest.begin(), possible_dest.end());
    for (const int& dest: possible_dest) cout << dest << " ";
    cout << "\n";
  }

  return 0;
}

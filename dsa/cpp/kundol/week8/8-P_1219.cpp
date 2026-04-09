#include <bits/stdc++.h>
using namespace std;

int main(int argc, char **argv) {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int N, M, A, B;
  cin >> N >> A >> B >> M;

  vector<pair<int, int>> adj[50];
  for (int i = 0; i < M; i++) {
    int from, to, cost;
    cin >> from >> to >> cost;
    adj[from].push_back({to, cost});
  }

  const long long NEGINF = -(1LL << 60);
  long long balance[50];
  fill(balance, balance + 50, NEGINF);

  int pay[50];
  for (int i = 0; i < N; i++) cin >> pay[i];

  balance[A] = pay[A];
  vector<int> cycle_nodes;
  for (int i = 0; i < N; i++) {
    for (int u = 0; u < N; u++) {
      if (balance[u] == NEGINF) continue;
      for (auto [v, cost] : adj[u]) {
        long long next = balance[u] + pay[v] - cost;
        if (next > balance[v]) {
          balance[v] = next;
          if (i == N - 1) cycle_nodes.push_back(v);
        }
      }
    }
  }

  vector<bool> visited(N, false);
  queue<int> q;
  for (int node : cycle_nodes) {
    q.push(node);
    visited[node] = true;
  }
  while (!q.empty()) {
    int u = q.front(); q.pop();
    if (u == B) {
      cout << "Gee\n";
      return 0;
    }
    for (auto [v, cost] : adj[u]) {
      if (!visited[v]) {
        visited[v] = true;
        q.push(v);
      }
    }
  }

  if (balance[B] == NEGINF) cout << "gg\n";
  else cout << balance[B] << "\n";

  return 0;
}

#include <bits/stdc++.h>
using namespace std;

int T, N, M, cnt;
vector<int> adj[1001];
int visited[1001];
bool isGraph = false, hasCycle = false;

void dfs(int id, int prev_id) {
  for (int next_id : adj[id]) {
    if (next_id == prev_id) continue;
    if (visited[next_id]) {
      hasCycle = true;
      break;
    }
    visited[next_id] = 1;
    dfs(next_id, id);
  }
}

int main(int argc, char **argv) {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  cin >> T;

  while (T--) {
    for (int i = 0; i < 1001; i++) adj[i].clear();
    fill(visited, visited + 1001, 0);
    cnt = 0;
    isGraph = false;
    hasCycle = false;

    cin >> N;
    cin >> M;

    if (M != N - 1) isGraph = true;

    while (M--) {
      int A, B;
      cin >> A >> B;
      adj[A].push_back(B);
      adj[B].push_back(A);
    }

    if (isGraph) {
      cout << "graph\n";
      continue;
    }

    for (int i = 1; i <= N; i++) {
      if (!visited[i]) {
        dfs(i, 0);
        cnt++;
      }
      if (cnt > 1) break;
    }

    if (cnt != 1 || hasCycle) {
      cout << "graph\n";
      continue;
    }

    cout << "tree\n";
  }

  return 0;
}

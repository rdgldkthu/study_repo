#include <bits/stdc++.h>
using namespace std;

int main(int argc, char **argv) {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int N, M, X;
  cin >> N >> M >> X;

  vector<int> adj[100001], radj[100001];
  for (int i = 0; i < M; i++) {
    int A, B;
    cin >> A >> B;
    adj[A].push_back(B);
    radj[B].push_back(A);
  }

  int U = 1, V = N;
  queue<int> q;
  vector<bool> visited(N + 1, false);
  visited[X] = true;
  q.push(X);

  while (!q.empty()) {
    int cur = q.front();
    q.pop();
    for (int next : radj[cur]) {
      if (!visited[next]) {
        U++;
        visited[next] = true;
        q.push(next);
      }
    }
  }

  visited.resize(N + 1, false);
  visited[X] = true;
  q.push(X);

  while (!q.empty()) {
    int cur = q.front();
    q.pop();
    for (int next : adj[cur]) {
      if (!visited[next]) {
        V--;
        visited[next] = true;
        q.push(next);
      }
    }
  }

  cout << U << " " << V << "\n";

  return 0;
}

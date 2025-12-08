#include <bits/stdc++.h>

using namespace std;

vector<int> adj[10001];
int visited[10001], trust[10001];

int DFS(int curr) {
  visited[curr] = 1;
  int cnt = 1;

  for (int &next : adj[curr]) {
    if (visited[next]) continue;
    cnt += DFS(next);
  }

  return cnt;
}

int main(int argc, char **argv) {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  int N, M;
  cin >> N >> M;

  while (M--) {
    int A, B;
    cin >> A >> B;
    adj[B].push_back(A);
  }

  int max_cnt = 0;
  for (int i = 1; i <= N; ++i) {
    memset(visited, 0, sizeof(visited));
    trust[i] = DFS(i);
    max_cnt = max(max_cnt, trust[i]);
  }

  for (int i = 1; i <= N; ++i) {
    if (trust[i] == max_cnt) {
        cout << i << ' ';
    }
  }
  cout << '\n';

  return 0;
}
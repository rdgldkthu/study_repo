#include <bits/stdc++.h>

using namespace std;

bool visited[2][500004];

int main(int argc, char **argv) {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int N, K;
  cin >> N >> K;
  if (N == K) {
    cout << 0 << '\n';
    return 0;
  }

  queue<int> q;
  visited[0][N] = true;
  q.push(N);

  int flag = 0, seconds = 1;
  while (!q.empty()) {
    K += seconds;
    if (K > 500000) break;
    if (visited[seconds % 2][K]) {
      flag = 1;
      break;
    }

    int q_size = q.size();
    while (q_size--) {
      int cur_N = q.front();
      q.pop();
      for (int next_N : {cur_N - 1, cur_N + 1, 2 * cur_N}) {
        if (next_N < 0 || next_N > 500000 || visited[seconds % 2][next_N]) continue;
        visited[seconds % 2][next_N] = true;
        if (next_N == K) {
          flag = 1;
          break;
        }
        q.push(next_N);
      }
      if (flag) break;
    }
    if (flag) break;
    seconds++;
  }
  if (flag) cout << seconds << '\n';
  else cout << -1 << '\n';
  return 0;
}
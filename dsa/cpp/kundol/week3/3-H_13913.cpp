#include <bits/stdc++.h>

using namespace std;

int parent[100001];
int visited[100001];
queue<pair<int, int>> q;

int main(int argc, char **argv) {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  int N, K;
  cin >> N >> K;

  q.push({0, N}); // time, pos
  visited[N] = 1;

  while (!q.empty()) {
    int cur_time = q.front().first;
    int cur_pos = q.front().second;
    q.pop();

    if (cur_pos == K) {
      cout << cur_time << '\n';
      vector<int> route;
      int cur = K;
      while (cur != N) {
        route.push_back(cur);
        cur = parent[cur];
      }
      route.push_back(N);
      reverse(route.begin(), route.end());
      for (const int &pos : route)
        cout << pos << " ";
      cout << '\n';
      break;
    }

    int next_positions[3] = {cur_pos - 1, cur_pos + 1, 2 * cur_pos};
    int next_time = cur_time + 1;
    for (int next_pos : next_positions) {
      if (next_pos < 0 || next_pos > 100000 || visited[next_pos])
        continue;
      visited[next_pos] = next_time;
      parent[next_pos] = cur_pos;
      q.push({next_time, next_pos});
    }
  }

  return 0;
}
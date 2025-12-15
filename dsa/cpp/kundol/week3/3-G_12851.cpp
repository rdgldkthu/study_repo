#include <bits/stdc++.h>

using namespace std;

int visited[100001];
queue<pair<int, int>> q; // time, pos

int main(int argc, char **argv) {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  int N, K;
  cin >> N >> K;

  if (N == K) {
    cout << 0 << '\n' << 1 << '\n';
    return 0;
  }

  q.push({0, N}); // {time, pos}
  visited[N] = 1;

  int min_time = 0;
  int cnt = 0;

  // BFS
  while (!q.empty()) {
    int cur_time = q.front().first;
    int cur_pos = q.front().second;
    q.pop();

    if (min_time > 0 && cur_time > min_time)
      continue;

    if (cur_pos == K) {
      if (min_time == 0) {
        min_time = cur_time;
        cnt++;
      } else if (cur_time == min_time) {
        cnt++;
      }
      continue;
    }

    int next_positions[3] = {cur_pos - 1, cur_pos + 1, 2 * cur_pos};
    int next_time = cur_time + 1;
    for (int next_pos : next_positions) {
      if (next_pos < 0 || next_pos > 100000)
        continue;
      if (!visited[next_pos] || visited[next_pos] == next_time) {
        visited[next_pos] = next_time;
        q.push({next_time, next_pos});
      }
    }
  }

  cout << min_time << '\n' << cnt << '\n';

  return 0;
}
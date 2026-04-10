#include <bits/stdc++.h>
using namespace std;
using tiii = tuple<int, int, int>;

int main(int argc, char **argv) {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  const int dy[] = {-1, 0, 1, 0};
  const int dx[] = {0, 1, 0, -1};
  const int INF = 1e9;
  const int N_MAX = 125;
  int cost[N_MAX][N_MAX], min_cost[N_MAX][N_MAX];

  int problem_id = 1;
  while (true) {
    int N;
    cin >> N;
    if (N == 0) break;

    for (int y = 0; y < N; y++) {
      for (int x = 0; x < N; x++) {
        cin >> cost[y][x];
        min_cost[y][x] = INF;
      }
    }

    priority_queue<tiii, vector<tiii>, greater<tiii>> pq;
    pq.push({cost[0][0], 0, 0});
    min_cost[0][0] = cost[0][0];

    while (!pq.empty()) {
      tiii curr = pq.top(); pq.pop();
      int curr_cost = get<0>(curr);
      int curr_y = get<1>(curr);
      int curr_x = get<2>(curr);

      if (curr_cost != min_cost[curr_y][curr_x]) continue;

      for (int i = 0; i < 4; i++) {
        int next_y = curr_y + dy[i];
        int next_x = curr_x + dx[i];
        if (next_y < 0 || next_y >= N || next_x < 0 || next_x >= N) continue;
        int total_cost = curr_cost + cost[next_y][next_x];
        if (total_cost < min_cost[next_y][next_x]) {
          min_cost[next_y][next_x] = total_cost;
          pq.push({total_cost, next_y, next_x});
        }
      }
    }

    cout << "Problem " << problem_id++ << ": " << min_cost[N - 1][N -1] << "\n";
  }

  return 0;
}

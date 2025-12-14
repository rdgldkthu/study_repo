#include <bits/stdc++.h>

using namespace std;

int visited[61][61][61];
const int attack[6][3] = {{9, 3, 1}, {9, 1, 3}, {3, 9, 1},
                          {3, 1, 9}, {1, 9, 3}, {1, 3, 9}};

int solve2(vector<int> &v) {
  int cnt = 0;
  while (true) {
    if (v[0] + v[1] == 0)
      break;
    sort(v.begin(), v.end());
    v[0] = v[0] - 3 >= 0 ? v[0] - 3 : 0;
    v[1] = v[1] - 9 >= 0 ? v[1] - 9 : 0;
    cnt++;
  }
  return cnt;
}

int solve3(int a0, int b0, int c0) {
  queue<tuple<int, int, int>> q;
  visited[a0][b0][c0] = 1;
  q.push({a0, b0, c0});

  while (!q.empty()) {
    auto [a, b, c] = q.front();
    q.pop();

    for (int i = 0; i < 6; ++i) {
      auto [da, db, dc] = attack[i];
      int na = a - da > 0 ? a - da : 0;
      int nb = b - db > 0 ? b - db : 0;
      int nc = c - dc > 0 ? c - dc : 0;
      if (!visited[na][nb][nc]) {
        visited[na][nb][nc] = visited[a][b][c] + 1;
        q.push({na, nb, nc});
      }
    }
  }

  return visited[0][0][0] - 1;
}

int main(int argc, char **argv) {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  int N;
  cin >> N;

  vector<int> scv(N);
  for (int i = 0; i < N; ++i) {
    cin >> scv[i];
  }

  if (N == 1) {
    cout << ceil(static_cast<float>(scv[0]) / 9) << endl;
  } else if (N == 2) {
    cout << solve2(scv) << endl;
  } else if (N == 3) {
    cout << solve3(scv[0], scv[1], scv[2]) << endl;
  }
  return 0;
}
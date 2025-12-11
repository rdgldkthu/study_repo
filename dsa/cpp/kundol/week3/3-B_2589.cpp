#include <bits/stdc++.h>

using namespace std;

int H, W;
char a[50][50], visited[50][50];

const int dy[4] = {-1, 0, 1, 0};
const int dx[4] = {0, 1, 0, -1};

int main(int argc, char **argv) {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  // Input map size
  cin >> H >> W;

  // Input map
  for (int i = 0; i < H; ++i) {
    string h;
    cin >> h;
    for (int j = 0; j < W; ++j) {
      a[i][j] = h[j];
    }
  }

  // Solve using BFS
  int ans = 0;
  for (int i = 0; i < H; ++i) {
    for (int j = 0; j < W; ++j) {
      // Continue if not land
      if (a[i][j] == 'W')
        continue;
      // Preparation for BFS
      memset(visited, 0, sizeof(visited));
      queue<pair<int, int>> q;
      q.push({i, j});
      visited[i][j] = 1;
      // BFS
      while (!q.empty()) {
        int y = q.front().first;
        int x = q.front().second;
        q.pop();
        for (int k = 0; k < 4; ++k) {
          int ny = y + dy[k];
          int nx = x + dx[k];
          if (ny < 0 || ny >= H || nx < 0 || nx >= W)
            continue;
          if (a[ny][nx] == 'L' && !visited[ny][nx]) {
            q.push({ny, nx});
            // Store distance in the visited array (Note this starts from 1 instead of 0)
            int dist = visited[y][x] + 1;
            visited[ny][nx] = dist;
            ans = max(ans, dist);
          }
        }
      }
    }
  }

  // Output answer
  cout << ans - 1 << '\n';

  return 0;
}
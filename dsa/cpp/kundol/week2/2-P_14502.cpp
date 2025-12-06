#include <bits/stdc++.h>

using namespace std;

int N, M; // 3 <= N, M <= 8
int lab_map[8][8];
int visited[8][8];
const int dy[] = {-1, 0, 1, 0};
const int dx[] = {0, 1, 0, -1};

pair<int, int> idx2coor(const int &idx) {
  return pair<int, int>(idx / M, idx % M);
}

void spreadPoison(int y, int x) {
  visited[y][x] = 1;
  for (int i = 0; i < 4; ++i) {
    int ny = y + dy[i];
    int nx = x + dx[i];
    if (ny < 0 || ny >= N || nx < 0 || nx >= M)
      continue;
    if (!lab_map[ny][nx] && !visited[ny][nx]) {
      lab_map[ny][nx] = 3;
      spreadPoison(ny, nx);
    }
  }
}

void resetPoison() {
  for (int y = 0; y < N; ++y)
    for (int x = 0; x < M; ++x)
      if (lab_map[y][x] == 3)
        lab_map[y][x] = 0;
}

int countSafeArea(int y, int x) {
  visited[y][x] = 1;
  int area = 1;
  for (int i = 0; i < 4; ++i) {
    int ny = y + dy[i];
    int nx = x + dx[i];
    if (ny < 0 || ny >= N || nx < 0 || nx >= M)
      continue;
    if (!lab_map[ny][nx] && !visited[ny][nx])
      area += countSafeArea(ny, nx);
  }
  return area;
}

int main(int argc, char **argv) {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> N >> M;

  for (int i = 0; i < N; ++i) {
    for (int j = 0; j < M; ++j) {
      cin >> lab_map[i][j];
    }
  }

  int ans = 0;
  // iterate through all possible wall positions
  for (int i = 0; i < N * M - 2; ++i) {
    pair<int, int> wall1 = idx2coor(i);
    if (lab_map[wall1.first][wall1.second])
      continue;
    lab_map[wall1.first][wall1.second] = 1;
    for (int j = i + 1; j < N * M - 1; ++j) {
      pair<int, int> wall2 = idx2coor(j);
      if (lab_map[wall2.first][wall2.second])
        continue;
      lab_map[wall2.first][wall2.second] = 1;
      for (int k = j + 1; k < N * M; ++k) {
        pair<int, int> wall3 = idx2coor(k);
        if (lab_map[wall3.first][wall3.second])
          continue;
        lab_map[wall3.first][wall3.second] = 1;

        memset(visited, 0, sizeof(visited));
        // spread poison
        for (int y = 0; y < N; ++y)
          for (int x = 0; x < M; ++x)
            if (lab_map[y][x] == 2 && !visited[y][x])
              spreadPoison(y, x);

        // count safe area
        int safe_area = 0;
        for (int y = 0; y < N; ++y)
          for (int x = 0; x < M; ++x)
            if (lab_map[y][x] == 0 && !visited[y][x])
              safe_area += countSafeArea(y, x);

        // reset poison
        resetPoison();

        ans = max(ans, safe_area);

        lab_map[wall3.first][wall3.second] = 0;
      }
      lab_map[wall2.first][wall2.second] = 0;
    }
    lab_map[wall1.first][wall1.second] = 0;
  }

  cout << ans << '\n';

  return 0;
}
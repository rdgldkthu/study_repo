#include <bits/stdc++.h>
using namespace std;

int N, M, K, nutrients[11][11], A[11][11], ans = 0;
deque<int> land[11][11];

const int dy[8] = {-1, -1, -1, 0, 1, 1, 1, 0};
const int dx[8] = {-1, 0, 1, 1, 1, 0, -1, -1};

void springsummer() {
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      if (land[i][j].empty()) continue;
      deque<int> alive;
      int dead_trees = 0;
      for (int age : land[i][j]) {
        if (nutrients[i][j] < age) {
          dead_trees += age / 2;
        } else {
          nutrients[i][j] -= age;
          alive.push_back(age + 1);
        }
      }
      nutrients[i][j] += dead_trees;
      land[i][j] = alive;
    }
  }
}

void fall() {
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      if (land[i][j].empty()) continue;
      for (int &t : land[i][j]) {
        if (t % 5 == 0) {
          for (int k = 0; k < 8; k++) {
            int y = i + dy[k];
            int x = j + dx[k];
            if (y < 0 || y >= N || x < 0 || x >= N) continue;
            land[y][x].push_front(1);
          }
        }
      }
    }
  }
}

void winter() {
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      nutrients[i][j] += A[i][j];
    }
  }
}

int main(int argc, char **argv) {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  fill(&nutrients[0][0], &nutrients[0][0] + 11 * 11, 5);

  cin >> N >> M >> K;

  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      cin >> A[i][j];
    }
  }

  for (int i = 0; i < M; i++) {
    int x, y, z;
    cin >> x >> y >> z;
    land[x - 1][y - 1].push_back(z);
  }

  for (int i = 0; i < K; i++) {
    springsummer();
    fall();
    winter();
  }

  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      ans += land[i][j].size();
    }
  }

  cout << ans << '\n';

  return 0;
}

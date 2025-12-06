#include <bits/stdc++.h>

using namespace std;

int N, M;
int a[100][100];
int visited[100][100];
const int dy[] = {-1, 0, 1, 0};
const int dx[] = {0, 1, 0, -1};

void spreadAir(int y, int x) {
  visited[y][x] = 1;
  a[y][x] = 2;
  for (int i = 0; i < 4; ++i) {
    int ny = y + dy[i];
    int nx = x + dx[i];
    if (ny < 0 || ny >= N || nx < 0 || nx >= M)
      continue;
    if (a[ny][nx] != 1 && !visited[ny][nx])
      spreadAir(ny, nx);
  }
}

void meltCheeseEdge() {
  for (int y = 0; y < N; ++y) {
    for (int x = 0; x < M; ++x) {
      if (a[y][x] == 1) {
        for (int i = 0; i < 4; ++i) {
          int ny = y + dy[i];
          int nx = x + dx[i];
          if (ny < 0 || ny >= N || nx < 0 || nx >= M)
            continue;
          if (a[ny][nx] == 2) {
            a[y][x] = 0;
            continue;
          }
        }
      }
    }
  }
}

int countCheese() {
  int cnt = 0;
  for (int y = 0; y < N; ++y)
    for (int x = 0; x < M; ++x)
      if (a[y][x] == 1)
        cnt++;
  return cnt;
}

int main(int argc, char **argv) {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> N >> M;

  for (int i = 0; i < N; ++i)
    for (int j = 0; j < M; ++j)
      cin >> a[i][j];

  int hrs = 0, cnt = countCheese();

  if (!cnt) {
    cout << hrs << '\n' << cnt << '\n';
    return 0;
  }

  while (true) {
    memset(visited, 0, sizeof(visited));
    spreadAir(0, 0);
    meltCheeseEdge();
    int temp = countCheese();
    hrs++;
    if (temp == 0)
      break;
    cnt = temp;
  }

  cout << hrs << '\n' << cnt << '\n';

  return 0;
}
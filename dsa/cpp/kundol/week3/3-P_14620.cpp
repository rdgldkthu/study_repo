#include <bits/stdc++.h>

using namespace std;

int N, current_price = 0, min_price = 20001;
int land_price[11][11], visited[11][11];
const int dy[] = {-1, 0, 1, 0, -1, -1, 1, 1, -2, 0, 2, 0};
const int dx[] = {0, 1, 0, -1, -1, 1, -1, 1, 0, 2, 0, -2};

void plantSeed(int y, int x, int val) {
  visited[y][x] = val;
  for (int i = 0; i < 12; i++) {
    int ny = y + dy[i];
    int nx = x + dx[i];
    if (ny < 1 || ny > N || nx < 1 || nx > N) continue;
    if (visited[ny][nx]) continue;
    visited[ny][nx] = val;
  }
}

void unplantSeed(int y, int x, int val) {
  visited[y][x] = 0;
  for (int i = 0; i < 12; i++) {
    int ny = y + dy[i];
    int nx = x + dx[i];
    if (ny < 1 || ny > N || nx < 1 || nx > N) continue;
    if (visited[ny][nx] == val)
      visited[ny][nx] = 0;
  }
}

void updatePrice(int y, int x, char op) {
  if (op == '+') {
    current_price += land_price[y][x];
    for (int i = 0; i < 4; i++) {
      int ny = y + dy[i];
      int nx = x + dx[i];
      if (ny < 1 || ny > N || nx < 1 || nx > N) continue;
      current_price += land_price[ny][nx];
    }
  } else if (op == '-') {
    current_price -= land_price[y][x];
    for (int i = 0; i < 4; i++) {
      int ny = y + dy[i];
      int nx = x + dx[i];
      if (ny < 1 || ny > N || nx < 1 || nx > N) continue;
      current_price -= land_price[ny][nx];
    }
  } else {
    cout << "Invalid Operation" << endl;
  }
}

void DFS(int cnt) {
  if (current_price > min_price) return;
  if (cnt == 3 && current_price < min_price) {
    min_price = current_price;
    return;
  }
  if (cnt >= 3) return;
  for (int ny = 2; ny < N; ny++) {
    for (int nx = 2; nx < N; nx++) {
      if (visited[ny][nx]) continue;
      plantSeed(ny, nx, cnt+1);
      updatePrice(ny, nx, '+');
      DFS(cnt + 1);
      unplantSeed(ny, nx, cnt+1);
      updatePrice(ny, nx, '-');
    }
  }
}

int main(int argc, char **argv) {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  cin >> N;

  for (int i = 1; i <= N; i++)
    for (int j = 1; j <= N; j++)
      cin >> land_price[i][j];

  DFS(0);

  cout << min_price << '\n';

  return 0;
}
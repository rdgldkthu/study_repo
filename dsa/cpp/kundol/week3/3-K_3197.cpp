#include <bits/stdc++.h>

using namespace std;

int R, C;
char lake[1500][1500];
const int dy[4] = {-1, 0, 1, 0};
const int dx[4] = {0, 1, 0, -1};
bool visited_water[1500][1500], visited_swan[1500][1500];
queue<pair<int, int>> water_q, water_q_temp, swan_q, swan_q_temp;

void defrost() {
  while (!water_q.empty()) {
    auto [y, x] = water_q.front();
    water_q.pop();
    for (int i = 0; i < 4; ++i) {
      int ny = y + dy[i];
      int nx = x + dx[i];
      if (ny < 0 || ny >= R || nx < 0 || nx >= C)
        continue;
      if (visited_water[ny][nx])
        continue;
      if (lake[ny][nx] == 'X') {
        visited_water[ny][nx] = true;
        water_q_temp.push({ny, nx});
        lake[ny][nx] = '.';
      }
    }
  }
}

bool moveSwan() {
  while (!swan_q.empty()) {
    auto [y, x] = swan_q.front();
    swan_q.pop();
    for (int i = 0; i < 4; ++i) {
      int ny = y + dy[i];
      int nx = x + dx[i];
      if (ny < 0 || ny >= R || nx < 0 || nx >= C)
        continue;
      if (visited_swan[ny][nx])
        continue;
      visited_swan[ny][nx] = true;
      if (lake[ny][nx] == '.')
        swan_q.push({ny, nx});
      else if (lake[ny][nx] == 'X')
        swan_q_temp.push({ny, nx});
      else if (lake[ny][nx] == 'L')
        return true;
    }
  }
  return false;
}

void clearQueue(queue<pair<int, int>> &q) {
  queue<pair<int, int>> empty;
  swap(q, empty);
}

int main(int argc, char **argv) {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  // Get input
  cin >> R >> C;
  int y0, x0;
  string s;
  for (int y = 0; y < R; ++y) {
    string s;
    cin >> s;
    for (int x = 0; x < C; ++x) {
      lake[y][x] = s[x];
      // Save the first swan's location
      if (s[x] == 'L') {
        y0 = y;
        x0 = x;
      }
      if (s[x] == 'L' || s[x] == '.') {
        visited_water[y][x] = true;
        water_q.push({y, x});
      }
    }
  }

  swan_q.push({y0, x0});
  visited_swan[y0][x0] = true;

  // Defrost layer by layer and check if the swans can meet
  int days = 0;
  while (true) {
    if (moveSwan())
      break;
    defrost();
    water_q = water_q_temp;
    swan_q = swan_q_temp;
    clearQueue(water_q_temp);
    clearQueue(swan_q_temp);
    days++;
  }

  cout << days << '\n';
  return 0;
}

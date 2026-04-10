#include <bits/stdc++.h>
using namespace std;

char cube[6][3][3];
map<char, int> letter2id({
    {'U', 0},
    {'D', 1},
    {'F', 2},
    {'B', 3},
    {'L', 4},
    {'R', 5}
});
map<int, vector<int>> adj_faces_order({
    {0, {3, 5, 2, 4}},
    {1, {2, 5, 3, 4}},
    {2, {0, 5, 1, 4}},
    {3, {0, 4, 1, 5}},
    {4, {0, 2, 1, 3}},
    {5, {0, 3, 1, 2}},
});
const pair<int,int> adj_row_col_dir[6][6] = {
  {{0, 0}, {0, 0}, {-1, 0}, {-1, 0}, {-1, 0}, {-1, 0}},
  {{0, 0}, {0, 0}, {+3, 0}, {+3, 0}, {+3, 0}, {+3, 0}},
  {{+3, 0}, {-1, 0}, {0, 0}, {0, 0}, {0, -3}, {0, +1}},
  {{-1, 0}, {+3, 0}, {0, 0}, {0, 0}, {0, +1}, {0, -3}},
  {{0, +1}, {0, +1}, {0, +1}, {0, -3}, {0, 0}, {0, 0}},
  {{0, -3}, {0, -3}, {0, -3}, {0, +1}, {0, 0}, {0, 0}}
};

void rotate(string cmd) {
  int face = letter2id[cmd[0]];
  char dir = cmd[1];

  char temp[3][3];
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) {
      temp[i][j] = cube[face][i][j];
    }
  }

  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) {
      if (dir == '+') cube[face][j][2 - i] = temp[i][j];
      else cube[face][2 - j][i] = temp[i][j];
    }
  }

  vector<int> order = adj_faces_order[face];
  vector<int> cc, pp;
  if (dir == '-') reverse(order.begin(), order.end());

  int last_side = order[3];
  auto [r, c] = adj_row_col_dir[face][last_side];
  if (r > 0) {
    for (int i = 0; i < 3; i++) {
      pp.push_back(cube[last_side][r - 1][i]);
    }
  } else if (r < 0) {
    for (int i = 2; i >= 0; i--) {
      pp.push_back(cube[last_side][abs(r) - 1][i]);
    }
  } else if (c > 0) {
    for (int i = 0; i < 3; i++) {
      pp.push_back(cube[last_side][i][c - 1]);
    }
  } else if (c < 0) {
    for (int i = 2; i >= 0; i--) {
      pp.push_back(cube[last_side][i][abs(c) - 1]);
    }
  }

  for (int side : order) {
    cc.clear();
    auto [r, c] = adj_row_col_dir[face][side];
    if (r > 0) {
      for (int i = 0; i < 3; i++) {
        cc.push_back(cube[side][r - 1][i]);
        cube[side][r - 1][i] = pp[i];
      }
    } else if (r < 0) {
      for (int i = 2; i >= 0; i--) {
        cc.push_back(cube[side][abs(r) - 1][i]);
        cube[side][abs(r) - 1][i] = pp[2 - i];
      }
    } else if (c > 0) {
      for (int i = 0; i < 3; i++) {
        cc.push_back(cube[side][i][c - 1]);
        cube[side][i][c - 1] = pp[i];
      }
    } else if (c < 0) {
      for (int i = 2; i >= 0; i--) {
        cc.push_back(cube[side][i][abs(c) - 1]);
        cube[side][i][abs(c) - 1] = pp[2 - i];
      }
    }
    pp.clear();
    pp = cc;
  }
}

int main(int argc, char **argv) {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int t;
  cin >> t;

  while (t--) {
    int n;
    cin >> n;

    for (int i = 0; i < 3; i++) {
      for (int j = 0; j < 3; j++) {
        cube[0][i][j] = 'w';
        cube[1][i][j] = 'y';
        cube[2][i][j] = 'r';
        cube[3][i][j] = 'o';
        cube[4][i][j] = 'g';
        cube[5][i][j] = 'b';
      }
    }

    for (int i = 0; i < n; i++) {
      string rot;
      cin >> rot;
      rotate(rot);
    }

    for (int i = 0; i < 3; i++) {
      for (int j = 0; j < 3; j++) {
        cout << cube[0][i][j];
      }
      cout << '\n';
    }
  }

  return 0;
}

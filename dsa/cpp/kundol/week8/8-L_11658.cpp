#include <bits/stdc++.h>
using namespace std;

vector<int> trees[1025];

void update(vector<int> &tree, int idx, int val) {
  while (idx < tree.size()) {
    tree[idx] += val;
    idx += idx & -idx;
  }
}

int sum(vector<int> &tree, int idx) {
  int ret = 0;
  while (idx > 0) {
    ret += tree[idx];
    idx -= idx & -idx;
  }
  return ret;
}

int main(int argc, char **argv) {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int N, M;
  cin >> N >> M;

  for (int i = 1; i <= N; i++) trees[i].resize(N + 1);

  for (int i = 1; i <= N; i++) {
    for (int j = 1; j <= N; j++) {
      int num;
      cin >> num;
      update(trees[i], j, num);
    }
  }

  for (int i = 0; i < M; i++) {
    int w;
    cin >> w;
    if (w == 0) {
      int x, y, c;
      cin >> x >> y >> c;
      int prev = sum(trees[x], y) - sum(trees[x], y - 1);
      update(trees[x], y, c - prev);
    } else if (w == 1) {
      int x1, y1, x2, y2;
      cin >> x1 >> y1 >> x2 >> y2;
      int total = 0;
      for (int j = x1; j <= x2; j++) {
        int temp = sum(trees[j], y2) - sum(trees[j], y1 - 1);
        total += temp;
      }
      cout << total << '\n';
    }
  }

  return 0;
}

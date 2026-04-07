#include <bits/stdc++.h>
using namespace std;

vector<int> tree;

void update(int id, int v) {
  while (id < tree.size()) {
    tree[id] += v;
    id += id & -id;
  }
}

int sum(int id) {
  int ret = 0;
  while (id > 0) {
    ret += tree[id];
    id -= id & -id;
  }
  return ret;
}

int main(int argc, char **argv) {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int T;
  cin >> T;

  int pos[100001];

  while (T--) {
    int n, m;
    cin >> n >> m;

    tree.clear();
    tree.resize(n + m + 2,0);

    for (int i = 1; i <= n; i++) {
      update(i + m, 1);
      pos[i] = i + m;
    }

    int top_id = m;

    for (int i = 0; i < m; i++) {
      int q;
      cin >> q;
      cout << sum(pos[q] - 1) << " ";
      update(pos[q], -1);
      pos[q] = top_id--;
      update(pos[q], 1);
    }
    cout << '\n';
  }

  return 0;
}

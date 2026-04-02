#include <bits/stdc++.h>
using namespace std;

int t, n, x, y;
vector<pair<int, int>> islands;
vector<int> fw_tree, y_coors;

int getid(int val) {
  int l = 0, r = y_coors.size() - 1;
  while (l <= r) {
    int m = (l + r) / 2;
    if (y_coors[m] == val) return m;
    if (y_coors[m] < val) l = m + 1;
    else r = m - 1;
  }
  return l;
}

void update(int pos, int val) {
  int id = pos;
  while (id <= n) {
    fw_tree[id] += val;
    id += (id & -id);
  }
}

int sum(int id) {
  int ret = 0;
  while (id > 0) {
    ret += fw_tree[id];
    id -= (id & -id);
  }
  return ret;
}

int main(int argc, char **argv) {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  cin >> t;

  while (t--) {
    cin >> n;
    islands.clear();
    y_coors.clear();
    fw_tree.clear();
    fw_tree.resize(n + 1);

    for (int i = 0; i < n; i++) {
      cin >> x >> y;
      islands.push_back({x, -1 * y});
      y_coors.push_back(-1 * y);
    }

    sort(islands.begin(), islands.end());
    sort(y_coors.begin(), y_coors.end());

    long long cnt = 0;

    update(getid(islands[0].second) + 1, 1);

    for (int i = 1; i < n; i++) {
      int id = getid(islands[i].second) + 1;
      cnt += 1LL * sum(id);
      update(id, 1);
    }

    cout << cnt << '\n';
  }

  return 0;
}

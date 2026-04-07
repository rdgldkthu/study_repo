#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void update(vector<ll> &tree, int idx, ll val) {
  while (idx < tree.size()) {
    tree[idx] += val;
    idx += idx & -idx;
  }
}

ll sum(vector<ll> &tree, int idx) {
  ll ret = 0;
  while (idx > 0) {
    ret += tree[idx];
    idx -= idx & -idx;
  }
  return ret;
}

int main(int argc, char **argv) {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  const int MAX = 200002;
  const ll MOD = 1'000'000'007LL;

  int N;
  cin >> N;

  vector<ll> cnt_tree, pos_tree;

  cnt_tree.resize(MAX, 0);
  pos_tree.resize(MAX, 0);

  int pos;
  cin >> pos; // first tree
  update(cnt_tree, pos + 1, 1);
  update(pos_tree, pos + 1, pos);

  ll ans = 1;
  for (int i = 2; i <= N; i++) {
    int pos;
    cin >> pos;

    ll l_cnt = sum(cnt_tree, pos);
    ll l_sum = sum(pos_tree, pos);

    ll total_cnt = sum(cnt_tree, MAX - 1);
    ll total_sum = sum(pos_tree, MAX - 1);

    ll r_cnt = total_cnt - sum(cnt_tree, pos + 1);
    ll r_sum = total_sum - sum(pos_tree, pos + 1);

    ll cost = pos * l_cnt - l_sum + r_sum - pos * r_cnt;

    ans = (ans * (cost % MOD)) % MOD;

    update(cnt_tree, pos + 1, 1);
    update(pos_tree, pos + 1, pos);
  }

  cout << ans << '\n';

  return 0;
}

#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int N, M, K;
vector<ll> tree;

void update(int idx, ll val) {
  while (idx < tree.size()) {
    tree[idx] += val;
    idx += idx & -idx;
  }
}

ll sum(int idx) {
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

  cin >> N >> M >> K;
  tree.resize(N + 1);

  for (int i = 1; i <= N; i++) {
    ll num;
    cin >> num;
    update(i, num);
  }

  for (int i = 0; i < M + K; i++) {
    ll a, b, c;
    cin >> a >> b >> c;
    if (a == 1) {
      ll prev = sum(b) - sum(b - 1);
      update(b, c - prev);
    } else if (a == 2) {
      ll range_sum = sum(c) - sum(b - 1);
      cout << range_sum << '\n';
    }
  }

  return 0;
}

#include <bits/stdc++.h>
using namespace std;

int main(int argc, char **argv) {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int ma, mb, ta, tb;
  cin >> ma >> mb >> ta >> tb;

  map<pair<int, int>, int> dist;
  queue<pair<int, int>> q;

  q.push({0, 0});
  dist[{0, 0}] = 0;

  while (!q.empty()) {
    pair<int, int> curr = q.front();
    q.pop();

    int ca = curr.first;
    int cb = curr.second;

    if (ca == ta && cb == tb) {
      cout << dist[{ta, tb}] << '\n';
      return 0;
    }

    pair<int, int> next_states[6] = {
      {ma, cb},
      {ca, mb},
      {0, cb},
      {ca, 0},
      {ca - min(ca, mb - cb), cb + min(ca, mb - cb)},
      {ca + min(cb, ma - ca), cb - min(cb, ma - ca)}
    };

    for (auto& next : next_states) {
      if (dist.find(next) == dist.end()) {
        dist[next] = dist[curr] + 1;
        q.push(next);
      }
    }

  }

  cout << -1 << '\n';

  return 0;
}

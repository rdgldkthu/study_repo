#include <bits/stdc++.h>

using namespace std;

int ingredients[15][5];
int N, mp, mf, ms, mv;
int sum_p, sum_f, sum_s, sum_v, sum_c;
int min_cost = 15 * 500 + 1;
map<int, vector<vector<int>>> dict;

int main(int argc, char **argv) {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  cin >> N;
  cin >> mp >> mf >> ms >> mv;

  for (int i = 0; i < N; i++) {
    cin >> ingredients[i][0] >> ingredients[i][1] >> ingredients[i][2] >>
        ingredients[i][3] >> ingredients[i][4];
  }

  for (int i = 1; i < (1 << N); i++) {
    sum_p = sum_f = sum_s = sum_v = sum_c = 0;
    vector<int> idxs;
    for (int j = 0; j < N; j++) {
      if (i & (1 << j)) {
        idxs.push_back(j + 1);
        sum_p += ingredients[j][0];
        sum_f += ingredients[j][1];
        sum_s += ingredients[j][2];
        sum_v += ingredients[j][3];
        sum_c += ingredients[j][4];
      }
    }
    if (sum_p < mp || sum_f < mf || sum_s < ms || sum_v < mv)
      continue;
    if (sum_c <= min_cost) {
      dict[sum_c].push_back(idxs);
      min_cost = sum_c;
    }
  }

  if (min_cost > 15 * 500) {
    cout << -1 << '\n';
  } else {
    sort(dict[min_cost].begin(), dict[min_cost].end());
    cout << min_cost << '\n';
    for (auto &idx : dict[min_cost][0])
      cout << idx << ' ';
    cout << '\n';
  }

  return 0;
}
#include <bits/stdc++.h>
using namespace std;

int N, C;
vector<int> weights;
vector<long long> sumA, sumB;

void getSum(int idx, int end, long long curr_sum, vector<long long> &targetSum) {
  if (curr_sum > C) return;
  if (idx == end) {
    targetSum.push_back(curr_sum);
    return;
  }
  getSum(idx + 1, end, curr_sum, targetSum);
  getSum(idx + 1, end, curr_sum + weights[idx], targetSum);
}

int main(int argc, char **argv) {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  cin >> N >> C;

  weights.resize(N);
  for (int i = 0; i < N; i++) cin >> weights[i];

  getSum(0, N / 2, 0, sumA);
  getSum(N / 2, N, 0, sumB);

  sort(sumB.begin(), sumB.end());

  long long ans = 0;
  for (long long& a : sumA) {
    auto it = upper_bound(sumB.begin(), sumB.end(), C - a);
    ans += (it - sumB.begin());
  }

  cout << ans << '\n';

  return 0;
}

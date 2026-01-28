#include <bits/stdc++.h>
using namespace std;

int main(int argc, char **argv) {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int N;
  cin >> N;

  int nums[11];
  for (int i = 0; i < N; i++) cin >> nums[i];

  vector<int> ops; // 0:+, 1:-, 2:*, 3:/
  for (int i = 0; i < 4; i++) {
    int cnt; cin >> cnt;
    for (int j = 0; j < cnt; j++) ops.push_back(i);
  }

  long long min_res = 1e9 + 1, max_res = -1e9 - 1;
  do {
    long long temp = nums[0];
    for (int i = 0; i < N - 1; i++) {
      int next_num = nums[i + 1];
      int op = ops[i];
      if (op == 0) temp += next_num;
      else if (op == 1) temp -= next_num;
      else if (op == 2) temp *= next_num;
      else if (op == 3) temp /= next_num;
    }
    min_res = min(min_res, temp);
    max_res = max(max_res, temp);
  }while (next_permutation(ops.begin(), ops.end()));

  cout << max_res << '\n' << min_res << '\n';

  return 0;
}

#include <bits/stdc++.h>

using namespace std;

map<int, vector<int>> add_map = {
    {19, {994, 997}},
    {109, {934, 967}},
    {1009, {334, 667}}};

long long solve(int target_idx) {
  long long num = 666;
  int k = 0, idx = 1, rem_idx = 1, add_idx;

  while (true) {
    if (k % 100 == 66)
      add_idx = 1009;
    else if (k % 10 == 6)
      add_idx = 109;
    else
      add_idx = 19;

    if (idx + add_idx > target_idx) {
      while(idx < target_idx) {
        if (rem_idx < 6)
          num += 1000;
        else if (rem_idx == 6)
          num += add_map[add_idx][0];
        else {
          if (rem_idx < add_idx - 3)
            num++;
          else if (rem_idx == add_idx - 3)
            num += add_map[add_idx][1];
          else
            num += 1000;
        }
        rem_idx++;
        idx++;
      }
      break;
    }

    idx += add_idx;
    num += 10000;
    k++;
  }

  return num;
}

int main(int argc, char **argv) {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  int N;
  cin >> N;

  cout << solve(N) << '\n';

  return 0;
}
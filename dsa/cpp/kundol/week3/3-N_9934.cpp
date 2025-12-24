#include <bits/stdc++.h>

using namespace std;

int nums[1024];
vector<int> per_level[10];

void solve(int first, int last, int level) {
  int middle = (first + last) / 2;
  per_level[level].push_back(nums[middle]);
  if (first == last) return;
  solve(first, middle - 1, level + 1);
  solve(middle + 1, last, level + 1);
}

int main(int argc, char **argv) {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int K;
  cin >> K;

  int num_nodes = pow(2, K) - 1;

  for (int i = 0; i < num_nodes; ++i)
    cin >> nums[i];

  solve(0, num_nodes - 1, 0);

  for (int i = 0; i < K; ++i) {
    for (int &num : per_level[i])
      cout << num << ' ';
    cout << '\n';
  }

  return 0;
}
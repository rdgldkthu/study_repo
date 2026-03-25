#include <bits/stdc++.h>
using namespace std;

int N, M;
int nums[2002];

bool palin[2002][2002];

int main(int argc, char **argv) {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  cin >> N;
  for (int i = 1; i <= N; i++) cin >> nums[i];

  for (int diff = 0; diff < N; diff++) {
    for (int start = 1; start + diff <= N; start++) {
      int end = start + diff;
      if (start == end) palin[start][end] = true;
      else if (start + 1 == end) palin[start][end] = nums[start] == nums[end];
      else palin[start][end] = (nums[start] == nums[end]) && palin[start + 1][end - 1];
    }
  }

  cin >> M;
  for (int i = 0; i < M; i++) {
    int S, E;
    cin >> S >> E;
    cout << palin[S][E] << '\n';
  }

  return 0;
}

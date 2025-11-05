#include <bits/stdc++.h>

using namespace std;

int main(int argc, char **argv) {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  int N, M;
  cin >> N;
  cin >> M;

  vector<int> ids;
  ids.reserve(N);
  for (int i = 0; i < N; ++i) {
    int id;
    cin >> id;
    ids.push_back(id);
  }
  sort(ids.begin(), ids.end());

  auto start = ids.begin();
  auto end = ids.end();
  --end;

  int ans = 0;
  while (start != end) {
    int sum = *start + *end;
    if (sum == M) {
      ++ans;
      if (start + 1 == end)
        break;
      ++start;
      --end;
    } else if (sum < M) {
      ++start;
    } else {
      --end;
    }
  }

  cout << ans << '\n';

  return 0;
}
#include <bits/stdc++.h>
using namespace std;

int N, M, l = 1, r = 0;
vector<int> gems;

bool canDistribute(int mid) {
  long long cnt = 0;
  for (int i = 0; i < M; i++) {
    cnt += (gems[i] / mid);
    if (gems[i] % mid != 0) cnt++;
  }
  return cnt <= N;
}

int main(int argc, char **argv) {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  cin >> N >> M;

  gems.resize(M);
  for (int i = 0; i < M; i++) {
    cin >> gems[i];
    r = max(r, gems[i]);
  }

  int ans = r;
  while (l <= r) {
    int mid = (l + r) / 2;
    if (canDistribute(mid)) {
      ans = mid;
      r = mid - 1;
    } else {
      l = mid + 1;
    }
  }

  cout << ans << '\n';

  return 0;
}

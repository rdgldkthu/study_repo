#include <bits/stdc++.h>
using namespace std;

long long N, M;
vector<int> v;

bool solve(long long mid) {
  long long cnt = 0;
  for (int i = 0; i < M; i++) {
    cnt += ((mid / v[i]) + 1);
  }
  return cnt >= N;
}

int main(int argc, char **argv) {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  cin >> N >> M;
  v.resize(M);
  for (int i = 0; i < M; i++) cin >> v[i];

  if (M == 1) {
    cout << "1\n";
    return 0;
  }

  if (N <= M) {
    cout << N << '\n';
    return 0;
  }

  long long l = 0, r = 60'000'000'000, mid, T_min;
  while (l <= r) {
    mid = (l + r) / 2;
    if (solve(mid)) {
      T_min = mid;
      r = mid - 1;
    } else {
      l = mid + 1;
    }
  }

  long long cnt = 0, ans;

  for (int i = 0; i < M; i++) {
    cnt += ceil((long double)T_min / v[i]);
  }

  for (int i = 0; i < M; i++) {
    if (T_min % v[i] == 0) cnt++;
    if (cnt == N) {
      ans = i + 1;
      break;
    }
  }

  cout << ans << endl;

  return 0;
}

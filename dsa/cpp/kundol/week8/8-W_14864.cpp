#include <bits/stdc++.h>
using namespace std;

int main(int argc, char **argv) {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int N, M;
  cin >> N >> M;

  int ans[100001];
  for (int i = 1; i <= N; i++) ans[i] = i;

  for (int i = 0; i < M; i++) {
    int X, Y;
    cin >> X >> Y;
    ans[X]++;
    ans[Y]--;
  }

  vector<bool> used(N + 1, false);
  for (int i = 1; i <= N; i++) {
    if (used[ans[i]]) {
      cout << -1 << "\n";
      return 0;
    }
    used[ans[i]] = true;
  }

  for (int i = 1; i <= N; i++) cout << ans[i] << " ";
  cout << "\n";

  return 0;
}

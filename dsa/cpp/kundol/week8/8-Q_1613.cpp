#include <bits/stdc++.h>
using namespace std;

int main(int argc, char **argv) {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int n, k;
  cin >> n >> k;

  bool reachable[401][401];
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) {
      if (i == j) reachable[i][j] = true;
      else reachable[i][j] = false;
    }
  }

  for (int i = 0; i < k; i++) {
    int a, b;
    cin >> a >> b;
    reachable[a][b] = true;
  }

  for (int mid = 1; mid <= n; mid++) {
    for (int from = 1; from <= n; from++) {
      for (int to = 1; to <= n; to++) {
        reachable[from][to] = reachable[from][to] || (reachable[from][mid] && reachable[mid][to]);
      }
    }
  }

  int s;
  cin >> s;
  for (int i = 0; i < s; i++) {
    int a, b;
    cin >> a >> b;
    if (reachable[a][b]) cout << -1;
    else if (reachable[b][a]) cout << 1;
    else cout << 0;
    cout << '\n';
  }

  return 0;
}

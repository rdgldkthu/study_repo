#include <bits/stdc++.h>

using namespace std;

int N, L, ans = 0;
int a[100][100], b[100][100];

void solve(int arr[100][100]) {
  for (int i = 0; i < N; i++) {
    bool possible = true;
    int cnt = 1;
    int prev = arr[i][0];
    for (int j = 1; j < N; j++) {
      int curr = arr[i][j];
      if (prev == curr) {
        cnt++;
      } else if (abs(prev - curr) >= 2) { // more than 2 levels
        possible = false;
        break;
      } else if (prev - curr == 1) { // 1 level down
        if (cnt >= 0)
          cnt = -L + 1;
        else {
          possible = false;
          break;
        }
      } else if (prev - curr == -1) { // 1 level up
        if (cnt >= L)
          cnt = 1;
        else {
          possible = false;
          break;
        }
      }
      prev = curr;
    }
    if (cnt < 0)
      possible = false;
    if (possible)
      ans++;
  }
}

int main(int argc, char **argv) {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  cin >> N >> L;
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      cin >> a[i][j];
      b[j][i] = a[i][j];
    }
  }

  solve(a);
  solve(b);

  cout << ans << '\n';

  return 0;
}

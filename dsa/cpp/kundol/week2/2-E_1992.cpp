#include <bits/stdc++.h>

using namespace std;

int N;
int a[64][64];

void solve(int y, int x, int N) {
  int sum = 0;
  for (int i = y; i < y + N; ++i)
    for (int j = x; j < x + N; ++j)
      sum += a[i][j];

  if (sum == 0)
    cout << '0';
  else if (sum == N * N)
    cout << '1';
  else {
    cout << '(';
    if (N == 2) {
      cout << a[y][x] << a[y][x+1] << a[y+1][x] << a[y+1][x+1];
    }
    else {
        int nextN = N >> 1;
        solve(y, x, nextN);
        solve(y, x + nextN, nextN);
        solve(y + nextN, x, nextN);
        solve(y + nextN, x + nextN, nextN);
    }
    cout << ')';
  }
}

int main(int argc, char **argv) {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> N;
  for (int i = 0; i < N; ++i) {
    string temp;
    cin >> temp;
    for (int j = 0; j < N; ++j) {
      a[i][j] = temp[j] - '0';
    }
  }

  solve(0, 0, N);
  cout << '\n';

  return 0;
}
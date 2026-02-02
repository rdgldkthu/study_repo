#include <bits/stdc++.h>
using namespace std;

int ps, m, n, cnt = 0;
int a[1001], b[1001], a_psum[2002], b_psum[2002];
map<int,int> a_map, b_map;

int main(int argc, char **argv) {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  cin >> ps >> m >> n;

  for (int i = 0; i < m; i++) {
    cin >> a[i];
    if (i == 0) a_psum[i] = a[i];
    else a_psum[i] = a_psum[i - 1] + a[i];
  }
  for (int i = m; i <= 2 * m; i++) {
    a_psum[i] = a_psum[i - 1] + a[i - m];
  }

  for (int i = 0; i < n; i++) {
    cin >> b[i];
    if (i == 0) b_psum[i] = b[i];
    else b_psum[i] = b_psum[i - 1] + b[i];
  }
  for (int i = n; i <= 2 * n; i++) {
    b_psum[i] = b_psum[i - 1] + b[i - n];
  }

  for (int w = 1; w <= m; w++) {
    for (int st = w; st < m + w; st++) {
      int total = a_psum[st] - a_psum[st - w];
      a_map[total]++;
      if (w == m) break;
    }
  }

  for (int w = 1; w <= n; w++) {
    for (int st = w; st < n + w; st++) {
      int total = b_psum[st] - b_psum[st - w];
      b_map[total]++;
      if (w == n) break;
    }
  }

  cnt = a_map[ps] + b_map[ps];

  for (int w = 1; w < ps; w++) {
    cnt += a_map[w] * b_map[ps - w];
  }

  cout << cnt << '\n';

  return 0;
}

#include <bits/stdc++.h>
using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int T;
  cin >> T;

  while (T--) {
    int n, m;
    cin >> n >> m;

    queue<int> q;
    vector<int> priority(n);
    vector<int> p_left(10, 0);
    int curr_high = 0;
    for (int i = 0; i < n; i++) q.push(i);
    for (int i = 0; i < n; i++) {
      int p; cin >> p;
      priority[i] = p;
      p_left[p]++;
      curr_high = max(curr_high, p);
    }

    if (n == 1) {
      cout << 1 << "\n";
      continue;
    }

    int time = 0;
    while (!q.empty()) {
      int curr_job = q.front(); q.pop();
      int& curr_p = priority[curr_job];

      if (curr_p == curr_high) {
        time++;
        if (curr_job == m) break;
        p_left[curr_p]--;
        if (p_left[curr_p] == 0) while (p_left[curr_high--] == 0);
      } else {
        q.push(curr_job);
      }

    }

    cout << time << "\n";
  }

  return 0;
}

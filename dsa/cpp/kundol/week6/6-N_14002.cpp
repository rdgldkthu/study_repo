#include <bits/stdc++.h>
using namespace std;

int N, a[1001], cnt[1001], prev_list[1001];
vector<int> lis;

void go(int idx) {
  if (idx == -1) return;
  lis.push_back(a[idx]);
  go(prev_list[idx]);
}

int main(int argc, char **argv) {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  cin >> N;
  for (int i = 0; i < N; i++) cin >> a[i];

  fill(cnt, cnt + 1001, 1);
  fill(prev_list, prev_list + 1001, -1);

  int len = 1, last_idx = 0;
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < i; j++) {
      if (a[j] < a[i] && cnt[i] < cnt[j] + 1) {
        cnt[i] = cnt[j] + 1;
        prev_list[i] = j;
        if (len < cnt[i]) {
          len = cnt[i];
          last_idx = i;
        }
      }
    }
  }

  go(last_idx);
  cout << len << '\n';
  for (int i = len - 1; i >= 0; i--) cout << lis[i] << ' ';
  cout << '\n';

  return 0;
}

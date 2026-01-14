#include <bits/stdc++.h>
using namespace std;

int main(int argc, char **argv) {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int N;
  cin >> N;

  long long ans = 0;
  stack<pair<int, int>> st;

  for (int i = 0; i < N; i++) {
    int cur_h;
    cin >> cur_h;
    int same_h_cnt = 1;

    while (!st.empty() && st.top().first < cur_h) {
      ans += st.top().second;
      st.pop();
    }

    if (!st.empty()) {
      if (st.top().first == cur_h) {
        ans += st.top().second;
        same_h_cnt = st.top().second + 1;
        st.pop();
        if (!st.empty()) ans++;
      } else ans++;
    }

    st.push({cur_h, same_h_cnt});
  }

  cout << ans << '\n';

  return 0;
}

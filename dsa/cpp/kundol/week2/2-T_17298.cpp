#include <bits/stdc++.h>

using namespace std;

int N;
int arr[1'000'000];
int ans[1'000'000];

int main(int argc, char **argv) {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> N;

  for (int i = 0; i < N; ++i) {
    cin >> arr[i];
  }

  stack<int> st;

  for (int i = 0; i < N; ++i) {
    while (!st.empty() && arr[st.top()] < arr[i]) {
      ans[st.top()] = arr[i];
      st.pop();
    }
    st.push(i);
  }

  while (!st.empty()) {
    ans[st.top()] = -1;
    st.pop();
  }

  for (int i = 0; i < N; ++i) {
    cout << ans[i] << ' ';
  }
  cout << '\n';

  return 0;
}
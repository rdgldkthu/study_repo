#include <bits/stdc++.h>

using namespace std;

int main(int argc, char **argv) {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  int N;
  cin >> N;

  int ans = 0;
  for (int i = 0; i < N; ++i) {
    string word;
    cin >> word;

    stack<char> arches;
    for (auto &letter : word) {
        if (!arches.empty() && arches.top() == letter)
          arches.pop();
        else
          arches.push(letter);
    }
    if (arches.empty()) {
      ++ans;
    }
  }

  cout << ans << '\n';

  return 0;
}

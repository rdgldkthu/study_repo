#include <bits/stdc++.h>

using namespace std;

int main(int argc, char **argv) {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  int t;
  cin >> t;

  for (int i = 0; i < t; ++i) {
    int n;
    cin >> n;

    unordered_map<string, int> attributes;
    for (int j = 0; j < n; ++j) {
      string name, category;
      cin >> name >> category;
      attributes[category]++;
    }

    int ans = 1;
    for (auto &[k, v] : attributes) {
      ans *= (v + 1);
    }

    cout << ans - 1 << '\n';
  }

  return 0;
}
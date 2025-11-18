#include <bits/stdc++.h>

using namespace std;

int main(int argc, char **argv) {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  int N;
  cin >> N;

  vector<string> nums;

  while (N--) {
    string s;
    cin >> s;

    auto it = s.begin();
    while (it != s.end()) {
      if (!isdigit(*it)) {
        ++it;
        continue;
      }

      auto start = it;

      while (it != s.end() && isdigit(*it))
        ++it;

      string num(start, it);

      int pos = 0;
      while (pos < num.size() && num[pos] == '0')
        pos++;

      string clean = num.substr(pos);

      if (clean.empty())
        clean = "0";

      nums.push_back(clean);
    }
  }

  sort(nums.begin(), nums.end(), [](const string &a, const string &b) {
    if (a.size() != b.size())
      return a.size() < b.size();
    return a < b;
  });

  for (auto &e : nums)
    cout << e << '\n';

  return 0;
}
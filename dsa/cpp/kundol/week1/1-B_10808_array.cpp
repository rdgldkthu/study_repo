// Solve with array
#include <bits/stdc++.h>

using namespace std;

int cnt[26];

int main(int argc, char **argv) {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  string input;
  cin >> input;

  for (const auto &ch : input)
    cnt[ch-97]++;

  for (const auto &e : cnt)
    cout << e << " ";
  cout << endl;

  return 0;
}
#include <bits/stdc++.h>

using namespace std;

int main(int argc, char **argv) {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  string s;
  cin >> s;

  int oddCnt = 0;
  map<char, int> alphabet;
  for (auto &ch : s) {
    if (++alphabet[ch] % 2 != 0)
      oddCnt++;
    else
      oddCnt--;
  }

  string ans;
  if (oddCnt == 0) { // all even number of characters
    for (auto &[k, v] : alphabet)
      for (int i = 0; i < v / 2; ++i)
        ans += k;
    ans = ans + string(ans.rbegin(), ans.rend());
  } else if (oddCnt == 1) { // only one odd number character
    char oddChar;
    for (auto &[k, v] : alphabet) {
      if (v % 2 != 0)
        oddChar = k;
      for (int i = 0; i < v / 2; ++i) {
        ans += k;
      }
    }
    ans = ans + oddChar + string(ans.rbegin(), ans.rend());
  } else { // more than one odd number character
    ans = "I'm Sorry Hansoo";
  }

  cout << ans << '\n';

  return 0;
}

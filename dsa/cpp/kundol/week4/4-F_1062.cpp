#include <bits/stdc++.h>

using namespace std;

int N, K;
int words[50];

int generateBitCode(const string &word) {
  int code = 0;
  for (const char &ch : word)
    code |= (1 << (ch - 'a'));
  return code;
}

int countReadableWords(const int &mask) {
  int cnt = 0;
  for (int i = 0; i < N; i++) {
    if ((mask & words[i]) == words[i])
      cnt++;
  }
  return cnt;
}

int solve(int idx, int rem_k, int mask) {
  if (rem_k < 0)
    return 0;
  if (idx == 26)
    return countReadableWords(mask);
  int cnt = solve(idx + 1, rem_k - 1, mask | (1 << idx));
  if (idx != 'a' - 'a' && idx != 'n' - 'a' && idx != 't' - 'a' &&
      idx != 'i' - 'a' && idx != 'c' - 'a') {
    cnt = max(cnt, solve(idx + 1, rem_k, mask));
  }
  return cnt;
}

int main(int argc, char **argv) {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  cin >> N >> K;
  for (int i = 0; i < N; i++) {
    string word;
    cin >> word;
    words[i] = generateBitCode(word);
  }

  cout << solve(0, K, 0) << '\n';

  return 0;
}
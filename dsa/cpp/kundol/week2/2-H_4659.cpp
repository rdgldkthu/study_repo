#include <bits/stdc++.h>

using namespace std;

bool isVowel(const char &let) {
  return (let == 'a' || let == 'e' || let == 'i' || let == 'o' || let == 'u');
}

bool checkAcceptance(const string &pw) {
  bool containVowel = false;
  char prev;
  int vow_cnt = 0, con_cnt = 0;

  for (auto &let : pw) {
    if (isVowel(let)) {
      containVowel = true;
      vow_cnt++;
      con_cnt = 0;
    } else {
      con_cnt++;
      vow_cnt = 0;
    }

    if (vow_cnt == 3 || con_cnt == 3)
      return false; // 3 consecutive vowels/consonants

    if (let == prev && let != 'e' && let != 'o')
      return false; // 2 consecutive letter

    prev = let;
  }

  return containVowel;
}

int main(int argc, char **argv) {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  string pw;
  while (true) {
    cin >> pw;
    if (pw == "end")
      return 0;
    if (checkAcceptance(pw))
      cout << '<' << pw << '>' << " is acceptable.\n";
    else
      cout << '<' << pw << '>' << " is not acceptable.\n";
  }

  return 0;
}
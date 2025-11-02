#include <bits/stdc++.h>

using namespace std;

int cnt[26];
bool possible = false;

int main(int argc, char **argv) {
  int N;
  cin >> N;

  for (int i = 0; i < N; i++) {
    string name;
    cin >> name;
    cnt[name[0] - 97]++;
  }

  for (int i = 0; i < 26; i++) {
    if (cnt[i] >= 5) {
      possible = true;
      cout << static_cast<char>(97 + i);
    }
  }
  if (!possible)
    cout << "PREDAJA";
  cout << endl;
  return 0;
}
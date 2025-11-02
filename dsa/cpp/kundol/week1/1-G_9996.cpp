#include <bits/stdc++.h>

using namespace std;

int main(int argc, char **argv) {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  int N;
  cin >> N;

  string pattern;
  cin >> pattern;

  auto pos = pattern.find('*');
  string pref = pattern.substr(0, pos);
  string suf = pattern.substr(pos + 1);

  for (int i = 0; i < N; i++) {
    string file_name;
    cin >> file_name;

    if (file_name.size() < pref.size() + suf.size()) {
      cout << "NE\n";
      continue;
    }

    if (pref == file_name.substr(0, pref.size()) &&
        suf == file_name.substr(file_name.size() - suf.size())) {
      cout << "DA\n";
    } else {
      cout << "NE\n";
    }
  }

  return 0;
}
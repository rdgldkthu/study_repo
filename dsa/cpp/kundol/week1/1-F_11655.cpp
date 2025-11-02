#include <bits/stdc++.h>

using namespace std;

string ROT13(const string &s) {
  string converted;
  for (auto &let : s) {
    if (65 <= let && let <= 90)
      converted += (let - 65 + 13) % 26 + 65;
    else if (97 <= let && let <= 122)
      converted += (let - 97 + 13) % 26 + 97;
    else
      converted += let;
  }
  return converted;
}

int main(int argc, char **argv) {
  string S;
  std::getline(cin, S);

  cout << ROT13(S) << endl;

  return 0;
}
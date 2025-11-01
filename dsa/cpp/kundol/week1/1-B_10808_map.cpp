// Solve with map
#include <bits/stdc++.h>

using namespace std;

int main(int argc, char **argv) {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  map<char, int> alphabet;
  for (int i = 97; i < 97 + 26; i++) {
    alphabet[static_cast<char>(i)] = 0;
  }

  string input;
  cin >> input;

  for (const auto &ch : input)
    alphabet[ch]++;

  for (const auto &pair : alphabet)
    cout << pair.second << " ";
  cout << endl;

  return 0;
}
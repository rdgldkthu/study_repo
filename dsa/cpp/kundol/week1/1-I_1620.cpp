#include <bits/stdc++.h>

using namespace std;

int main(int argc, char **argv) {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  int N, M;
  cin >> N >> M;

  unordered_map<string, int> pokemons_s2i;  // string to int
  vector<string> pokemons_i2s(N + 1);       // int to string
  for (int i = 1; i <= N; ++i) {
    string name;
    cin >> name;
    pokemons_s2i[name] = i;
    pokemons_i2s[i] = name;
  }

  for (int i = 0; i < M; ++i) {
    string query;
    cin >> query;
    if (isdigit(query[0]))
      cout << pokemons_i2s[stoi(query)] << '\n';
    else
      cout << pokemons_s2i[query] << '\n';
  }

  return 0;
}
